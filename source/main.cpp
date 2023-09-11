#include <iostream>
#include "linked_list.h"
using namespace std;

int main(int argc, char** argv) {
  LinkedList<int> list;
  char choice = '-';
  int data;
  do{
    cin >> choice;
    if(choice == 'p'){
      list.print();
    }
    else if(choice == 'a'){
      cin >> data;
      list.push_front(data);
    }
    else if(choice == 'd'){
      list.pop_front();
    }
    else if(choice == 'r'){
      list.reverse();
    }
    else{
      ;
    }
  }while(choice != 'q');
}