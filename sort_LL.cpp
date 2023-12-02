// write a program to sort a linked list (0,1,2).

#include <iostream>
//#include <LinkedList.h>
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
};

void print ( Node* &head) {

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

void InsertAtTail ( Node* &tail , int d ) {
       Node* temp = new Node(d) ;
       tail -> next = temp ;
       tail = temp ;
 }

// through data replacement
/* 
Node* sortlist ( Node* &head ) {
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == 0)
        zerocount++;
        else if (temp -> data == 1) 
        onecount++;
        else if(temp -> data == 2) 
        twocount++;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL) {
        if(zerocount != 0) {
            temp -> data = 0;
            zerocount--;
        }
        else if(onecount != 0) {
            temp -> data = 1;
            onecount--;
        }
        else if(twocount != 0){
            temp -> data = 2;
            twocount--;
        }
        temp = temp -> next;
    }
    return head;
 }
 */


 void insertAtTail(Node* tail,Node* curr) {
        tail -> next = curr;
        tail = curr;
      }


// through link replacement
Node* sortlist(Node* head) {
      Node* zerohead = new Node(-1);
      Node* zerotail = zerohead;
      Node* onehead = new Node(-1);
      Node* onetail = onehead;
      Node* twohead = new Node(-1);
      Node* twotail = twohead;
      Node* curr = head;

      // create seprate list(0,1,2)
      while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insertAtTail(zerotail,curr);
        }
        else if(value == 1){
            insertAtTail(onetail,curr);
        }
        else if(value == 2) {
            insertAtTail(twotail,curr);
        }
         curr = curr -> next;
      }
      // merge the seperated lists
      // onelist is not empty
      if(onehead -> next != NULL) {
        zerotail -> next = onehead -> next;
      }
      else {
        zerotail -> next = twohead -> next;
      }
      onetail -> next = twohead -> next;
      twotail -> next = NULL;
     // setup head
     head = zerohead -> next;

     // delete dummy node
     delete zerohead;
     delete onehead;
     delete twohead;
     
     return head;

}

 

int main() {
        Node* node1 = new Node(0);
        Node* tail = node1;
        print(tail);
        InsertAtTail(tail,1);
        print(tail);

        InsertAtTail(tail,1);
        print(tail);

        InsertAtTail(tail,2);
        print(tail);

        InsertAtTail(tail,0);
        print(tail);
       Node* head = node1;
       cout<<endl;
      sortlist(head);
      print(head);

        return 0;
}