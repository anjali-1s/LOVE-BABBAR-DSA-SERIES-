// write a program to perform insertion , traverse and deletion in circular linked list .

#include <iostream>
using namespace std ;

class Node {
     public :
       int data ;
       Node* next ;

       // constructor 
       Node (int d) {
        this -> data = d ;
        this -> next = NULL ;
       }

       // distructor 
       ~Node () {
        int value = this -> data ;
        if( this -> next != NULL ) {
            delete next ;
            next = NULL ;
        }
        cout << "memory is free for node with data" << value << endl ;
       }
};

void Insertnode(Node* tail , int d , int element) {
    // assuming that the element is present int the list 

    // empty list 
    if (tail == NULL) {
        Node* newNode = new Node(d) ;
        tail = newNode ;
        newNode -> next = newNode ;
    }

    else {
        // non - empty list 
        // assuming that the element is present in the list 

        Node* curr = tail ;

        while(curr -> data != element) 
        {  
            curr = curr -> next ;
        }
        // element found -> curr is representing element wala node
         Node* temp = new Node(d) ;
         temp -> next = curr -> next ;
         curr -> next = temp ;
    }
}

// traverse the list----->>>

void print (Node* tail) {
    // empty list 
    if(tail == NULL) {
        cout << "empty list !" << endl;
        return ;
    }

    Node* temp = tail ;
    do {
        cout << tail -> data <<" ";
        tail = tail -> next ;
    } while (tail != temp) ;
    cout << endl;
}

// deletion 

void deletion (Node* tail , int value ) {
    // empty list 
    if (tail == NULL) {
        cout << "list is empty !" << endl ;
        return ;
    }

    else {
        // non empty 
        // assuming that value is present in the linked list 

        Node* prev = tail ;
        Node* curr = prev -> next ;
        while ( curr -> data != value ) {
            prev = curr ;
            curr = curr -> next ;
        }
        prev -> next = curr -> next ;

      // for the linked list which has 1 node
        if (curr == prev) { 
            tail = NULL ;
        }

        // >=  2 node
        if (tail == curr) {
            tail = prev ;
        }
        curr -> next = NULL ;
        delete curr ;
    }
  }

int main () {
    Node* node1 = new Node(24) ;
    cout << node1 -> data << endl ;
    cout << node1 -> next << endl ;

    Node* tail = node1;
    // empty list m insert kre

    Insertnode(tail,12,24);
    print(tail);

   Insertnode(tail,24,17);
   print(tail);

   deletion(tail,24);
   print(tail);
    return 0;
}