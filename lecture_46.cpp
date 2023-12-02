// write a program to reverse a linked list in k group .

#include <iostream>
using namespace std;

class Node {
      public :

         int data;
         Node* next;

         Node (int d) 
      {   
        this -> data = d;
        this -> next = NULL;
     }
};

// insert a new node at last

void InsertionAtlast (Node* &tail , int d)
{
    Node* temp = new Node(d) ;
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}

// to print a singly linked list
 

void print (Node* tail)
{
    Node * temp = tail;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


// reverse list in k group
Node* k_reverse(Node* head, int k) {
       // base case 
       if(head -> next == NULL) {
        return NULL;
       }
       // step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL  && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next ;
        count++;
    }

   // step :2  recursive 
   if(next != NULL) {
    head -> next = k_reverse(head,k);
   }
   // step 3: return head of the list
   return prev;
}

int main() {
       
        Node* node1 = new Node(20);
     cout << node1 -> data << endl;
     cout << node1 -> next << endl;

     Node* tail = node1;
     Node* head = node1;
     InsertionAtlast(tail,34);
     print(head);
   
     InsertionAtlast(tail,36);
     print(tail); 

    InsertionAtlast(tail,48);
     print(tail); 

     k_reverse(head ,2);
     print(head);
     return 0;
}