#include <iostream>
using namespace std;
template <typename T>
class LinkedList {
public:
  LinkedList() : head(NULL) {}

  // You need to implement the following functions. 
  // 
  ~LinkedList();
  void push_front(const T data);
  void pop_front();
  void reverse();
  void print() const;

private:
  
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}
    
    T data;
    ListNode* next;
  };

  ListNode* head;
};


template <typename T>
LinkedList<T>::~LinkedList(){
  if( head != NULL ){
    ListNode* target = head;
    ListNode* prev = head;
    while( target->next != NULL ){
      prev = target;
      target = target->next;
      delete prev;
      prev = NULL;
    }
  }
}

template <typename T>
void LinkedList<T>::pop_front(){
  if( head == NULL ){
    return;
  }
  if( head->next == NULL ){
    delete head;
    head = NULL;
  }
  if( head != NULL ){
    ListNode* prev = head;
    ListNode* target = head->next;
    while(target->next != NULL){
      prev = prev->next;
      target = target->next;
    }
    prev->next = NULL;
    delete target;
  }
}

template <typename T>
void LinkedList<T>::print() const{
  if( head != NULL ){
    ListNode* target = head;
    cout << target->data;
    while(target->next != NULL){
      target = target->next;
      cout << target->data;
    }
    return;
  }
}

template <typename T>
void LinkedList<T>::reverse(){
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

template <typename T>
void LinkedList<T>::push_front(const T data){
  if( head == NULL ){
    head = new ListNode(data);
  }
  else{
    ListNode* target = head;
    while(target->next != NULL){
      target = target->next;
    }
    target->next = new ListNode(data);
  }
}