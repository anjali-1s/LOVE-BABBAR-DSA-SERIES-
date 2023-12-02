// write a program to reverse a linked list .

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

// reverse a linked list  through iterative method
void reverse_list (Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
   // Node* forward = NULL;
    while (curr != NULL)
    {
        head = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = head;
    }
     head = prev;
} 


// through recursive method
/*void reverse_list(Node* &head)
{
    // base case
    if(head -> next == NULL) {
        return ;
    }
     reverse_list(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
}
*/


// to print middle of the linked list --->>>

int getlength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}

int find_middle(Node* head) {
    int len = getlength(head);
    int ans= (len/2);
 /* Node* temp = head ;
    int cnt = 0;
    while (cnt < ans) {
        temp = temp -> next ;
        cnt++;
    }*/
    return ans;
}

int main () {
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
    cout << endl;
     reverse_list(head);
    print(head);

    int resu= find_middle(head);
     cout<<resu<<endl;
     return 0;
}