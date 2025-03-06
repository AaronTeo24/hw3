#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    smaller = nullptr;
    larger = nullptr;
    return llhelper(head, smaller, larger, pivot);

}
void llhelper( Node *&head, Node *&smaller, Node *&larger, int pivot){
    if (head == nullptr){
        return;
      }
    
      if (head -> val <= pivot){
        smaller = head;
        head = head->next;
        smaller->next = nullptr;
    
        llhelper(head, smaller->next, larger, pivot);
    
    
      }
    
      else{
        larger = head;
        head = head->next;
        larger->next = nullptr;
    
        llhelper(head, smaller, larger->next, pivot);
      }
    


}
