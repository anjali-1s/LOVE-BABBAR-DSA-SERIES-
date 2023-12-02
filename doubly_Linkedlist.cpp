// doubly linked list ------>>>>>>

#include <iostream>
using namespace std;

class Node {
    public : 

    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    
    // distructor
    ~Node() {
        int value = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
         cout << " memory free for node with data "<<value <<endl;
    }

 
};

void print(Node* head ) {
    Node* temp = head;
    while ( temp != NULL ) {
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    
 }

  int getlength( Node* head ) {
      int len = 0; 
      Node* temp = head;
      while( temp != NULL ) {
        cout << temp -> data <<endl;;
        temp = temp -> next;
        len++;
      }
      return len;
 }

 // insert at head ---->>>
 void insertAtHead ( Node* &head , Node* tail , int d ) {

    // empty list
    if( head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d) ;
    temp -> next = head ;
    head -> prev = temp ;
    head = temp;
    }
 }

 // insert at tail ----->>>>>
 void insertAtTail ( Node* &tail , Node* head , int d ) {

    // empty list
    if( tail == NULL ) {
        Node* temp = new Node(d) ;
        tail = temp;
        head = temp;
    }

    else {
        Node* temp = new Node(d);
     tail -> next = temp ;
     temp -> prev = tail; 
     tail = temp;
    }
 }

 // insert at position 
 void insertAtPosition( Node* head , Node* tail , int position , int d ) {

    // insert at first
      if(position == 1 ) {
        insertAtHead(head,tail,d);
          return;
      }

      Node* temp =head;
      int cnt = 1;
      while ( cnt < position -1) {
        temp = temp -> next;
        cnt++;
      }
      
      // inserting at last position
      if ( temp -> next == NULL) {
          insertAtTail(tail,head,d);
          return;

          // if we have to insert at middle position then create a node for d
          Node* nodeToInsert = new Node(d);

          nodeToInsert -> next = temp -> next;
          temp -> next -> prev = nodeToInsert;
          temp -> next = nodeToInsert;
          nodeToInsert -> prev = temp;

      }
 }

 // deletion 
 void deleteNode(int position , Node* &head) {
    // delete first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
    }

    else {
        // deleting any middle or last node 
          Node* curr = head;
          Node* prev = NULL;

          int cnt = 1;
          while( cnt < position ) {
            prev = curr;
            curr = curr -> next;
            cnt++;
          }

          curr -> prev = NULL;
          curr -> prev = curr -> next;
          curr -> next = NULL;
          delete curr;
    }
 }


int main() {
     Node* node1 = new Node(12);
     Node* head = node1;
     //print(head);

     //cout <<getlength(head) <<endl;
    // Node* head = node1;
     Node* tail = node1;
     insertAtHead(head,tail,15);
     print(head);
     //cout<< "head :" << head->data << endl;
     //cout<< "tail :" << tail->data <<endl;
     
     //Node* tail = node1;
     insertAtTail(head,tail,16);
     print(tail);
     // cout<< "head :" << head->data << endl;
    // cout<< "tail :" << tail->data <<endl;

     insertAtTail(head,tail,10);
     print(tail);
      //cout<< "head :" << head->data << endl;
     //cout<< "tail :" << tail->data <<endl;

     insertAtTail(head,tail,11);
     print(tail);
      //cout<< "head :" << head->data << endl;
    // cout<< "tail :" << tail->data <<endl;

     insertAtTail(head,tail,19);
     print(tail);
     // cout<< "head :" << head->data << endl;
     //cout<< "tail :" << tail->data <<endl;
    
    // insertAtPosition(tail,head,2,100);
     //print(head);
     //cout<< "head :" << head->data << endl;
     //cout<< "tail :" << tail->data <<endl;

    // deleteNode(1,head);
     //print(head);
     //cout<< "head :" << head->data << endl;
    // cout<< "tail :" << tail ->data<<endl;
     return 0;
}