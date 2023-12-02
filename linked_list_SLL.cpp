// write a program to perform insertion , traverse and deletion in singly linked list .

#include <iostream>
using namespace std;

class Node {
     public :
         int data;
         Node* next;


        // constructor 

         Node(int d) {
            this -> data = d;
            this -> next = NULL;
         }
        
        // distructor 
      ~Node () {
        int value = this -> data ;
        // memory free 

        if (this -> next != NULL) {
             delete next ;
             this -> next = NULL ;
        }
        cout << "memory is free for node with data" << value << endl ;
      }
};

// insert at head --->>>>

void InsertAtHead ( Node* &head , int d ) {
    Node* temp = new Node(d);
    temp -> next = head ;
    head -> next = NULL ;
     head = temp  ;
}

// traverse the linked list ---->>>>

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
     
}

// insertion at tail ------>>>>>

void InsertAtTail ( Node* tail , int d ) {
       Node* temp = new Node(d) ;
       tail -> next = temp ;
       tail = temp ;
 }

 // insert at middle node ------>>>>>

 void InsertAtPosition ( Node* head , Node* tail , int position , int d ) {
          //insert at first 

          if (position == 1) {
            InsertAtHead(head,d);
            return ;
          }

          Node* temp = head ;
          int cnt = 1 ;
          while ( cnt < position - 1 ) {
            temp = temp -> next ;
            cnt++ ;
          }

          // insert at last 

         if ( temp -> next == NULL ) {
            InsertAtTail (tail,d);
            return ;
         }

         // insert at middle position 
         // create a  node for d
         Node* nodeToinsert = new Node(d) ;
         nodeToinsert -> next = temp -> next ;
         temp -> next = nodeToinsert ;
 }

 // deletion in singly linked list ---->>>>

 void deletion (int position , Node* head) {

    // delete first node or start node 

    if (position == 1) {
        Node* temp = head ;
        head = head -> next ;

        // memory free at starting node 

        temp -> next = NULL ;
        delete temp ;
    }

    else {
        // deleting any middle node or last node 

        Node* curr = head ;
        Node* prev = NULL ;
        int cnt = 1 ;
        while ( cnt < position ) {
            prev = curr ;
            curr = curr -> next ;
            cnt++ ;
        }
        prev -> next = curr -> next ;
        curr -> next = NULL ;
        delete curr ;
    }
 }



int main () {
      Node* node1 = new Node(12);
      cout << node1 -> data << endl;
      cout << node1 -> next << endl;

      Node* head = node1 ;
     
      InsertAtHead (head , 16);
     // print (head);

      Node* tail = node1 ;
      InsertAtTail (tail , 10);
      print(tail);

      InsertAtTail (tail , 24);
      print(tail);

      InsertAtTail (tail , 25);
      print(tail);

      InsertAtTail (tail , 39);
      print(tail);
      

     // InsertAtPosition (head , tail , 3 , 64);
      //print (head);

     // InsertAtPosition (head , tail , 2 , 44);
     // print (head);
      
    //  deletion(2,head);
     // print(tail);

   // deletion(3,head);
    //print(tail);

      return 0;
}