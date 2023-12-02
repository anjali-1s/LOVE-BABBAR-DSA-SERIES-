// write a program to create a singly linked list and perform all possible operations.
#include <iostream>
using namespace std;

class Node
{
     public:
           int data;
           Node* next;

           // constructor
           Node(int d)
           {
               this -> data = d;
               this -> next = NULL;
           }

           ~Node()
           {
               int value = this -> data;
               if(this -> next != NULL)
               {
                    delete next;
                    this -> next = NULL;
               }
               cout<<"Memory is free to use !"<<endl;
           }
};

// insert at head in a singly linked list
void InsertAtHead ( Node* &head , int d ) {
     Node* temp = new Node(d);
     temp -> next = head ;
     head -> next = NULL ;
     head = temp  ;
}

// Insert at last in a singly linked list

// traverse the linked list
void print ( Node* head) {

    if (head == NULL) {
        cout << "list is empty!"<< endl;
        return;
    }
      Node* temp = head ;
      while ( temp != NULL ) {
        cout << temp -> data <<" ";
        temp = temp -> next ;
    }
     cout<<endl;
}

int main()
{
     Node* node1 = new Node(20);
     cout<<node1 -> data <<endl;
     cout<<node1 -> next <<endl;

     // head pointed to next
     Node* head = node1;
     print(head);

     InsertAtHead(head,12);
     print(head);

     InsertAtHead(head,12);
     print(head);

     return 0;
}