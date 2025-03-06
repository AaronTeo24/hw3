#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void trickleUp(int index);
  void trickleDown(unsigned int index);

  std::vector<T> data;
  unsigned int d; //d-ary heap
  PComparator comp;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : data() , d(m) , comp(c){
  
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!!!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!!!");

  }
  // if (this->size() >  25){
    
  //   for (int i = 0 ; i < 10 ; i++){
  //     cout << this->data[i] << " " ;
  //   }
  //   cout << "END OF THIS ROUND!" << endl;
  // }
  std::swap(data[0], data[size()-1]);
  this->data.vector<T>::pop_back();
  trickleDown(0);

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return this->data.vector<T>::size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
    return this->data.vector<T>::size() == 0;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  
  this->data.vector<T>::push_back(item);
  
  trickleUp(this->data.size()-1);
  
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index){
  if (index == 0){
    return;
  }
  int parent = (index-1)/d;
  

  while (parent >= 0 && comp(data[index], data[parent])){
    
    std::swap(data[index], data[parent]);
    
    index = parent;
    if (index <= 0){
      break;
    }
    parent = (index-1)/d;
    
    
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(unsigned int index){
  if (d*index+1 >= this->data.vector<T>::size() ){
    
    return;
  }
  unsigned smallest = d*index+1;
  for (unsigned int i = 1 ; i < d ; i++){
    if (d*index+i+1 < this->size() ){
      if (comp(data[d*index + i + 1],data[smallest])){
        smallest = d*index+i+1;
      }
    }
    else{
      break;
    }
  }
  if (comp(data[smallest],data[index])){
    std::swap(data[smallest],data[index]);
    trickleDown(smallest);
  }


}

#endif

