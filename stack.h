#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate

using namespace std;

template <typename T>
class Stack : private std::vector<T>{

public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> data;

};

template <typename T>
Stack<T>::Stack(){

}

template <typename T>
Stack<T>::~Stack(){

}


template <typename T>
bool Stack<T>::empty() const{
    return this->data.vector<T>::size() == 0;
}

template <typename T>
size_t Stack<T>::size() const{
    return this->data.vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item){
    this->data.vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if (data.empty()){
        throw std::underflow_error("Empty");
    }
    else{
        this->data.vector<T>::pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const{
    if (data.empty()){
        throw std::underflow_error("Empty");
    }
    
    return this->data[size()-1];
    
}







#endif