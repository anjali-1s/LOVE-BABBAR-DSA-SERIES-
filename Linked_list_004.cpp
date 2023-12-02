// write a program to demonstrate circular linked list.
#include <iostream>
using namespace std;

class Node
{
     public :
        int data;
        Node* next;

        // constructor
        Node(int d)
        {
          this -> data = d;
          this -> next = NULL;
        }

        // destructor
        ~Node()
        {
          int value = this -> data;
          if(this -> next != NULL)
          {
               delete next;
               next = NULL;
          }
          cout<<"Memory is free for further use !"<<value<<endl;
        }
};

// insertion in CLL
void InsertionAtFirst(Node* tail,int d)
{
   // empty list 
   if(tail == NULL)
   {
     cout<<"list is empty!"<<endl;
     return;
   }

   Node* temp = new Node(d);
   temp -> data = d;
   temp -> next = tail -> next;
   tail -> next = temp;
}



void print(Node* tail)
{
   // Empty list
   if(tail == NULL)
   {
     cout<<"Empty list!"<<endl;
     return;
   }

   Node* temp = tail;
   while(temp != NULL)
   {
     cout<<tail -> data<<" ";
     tail = tail -> next;
   }
   cout<<endl;
}

int main()
{
     Node* node1 = new Node(24);
     cout<<node1 -> data<<" ";
     cout<<node1 -> next;
     
     cout<<endl;
     Node* tail = node1;
     //empty list m insert krne k lie
     InsertionAtFirst(tail,25);
     print(tail);

     InsertionAtLast(tail,28);
     print(tail);
     return 0;
}
