// write a program to reverse a linked list ----->>>>>

#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* head;
    Node* prev;


    // constructor
    Node(int d) {
       this -> data = d;
       this -> next = NULL;

    }
};

void insertAtlast(Node* &tail , int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}


void print (Node* tail)
{
    Node* temp = tail;

    while(temp != NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next;

    }
}


// Recursive 

Node* reverseList (Node* head)
{

     // empty list

    if ( head == NULL && head -> next == NULL )
    {
        return head;
    }
    Node* chhotahead = reverseList (head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return chhotahead;
}

// Iterative 
Node* ReverseList (Node* head)
{
    // empty list

    if ( head == NULL && head -> next == NULL )
    {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != 0)
    {
        forward = curr -> next ;
        curr -> next = head;
        prev = curr;
        curr = forward;
    }
    return prev;
}



int main ()
{
    Node* node1 = new Node(10);
    cout <<node1 -> data << endl;
    cout <<node1 -> next << endl;

    Node* tail = node1;
    print(tail);
    insertAtlast(tail , 13);
    print(tail);

    insertAtlast(tail , 35);
    print(tail);

    insertAtlast(tail , 23);
    print(tail);
    
   Node* head = node1;
    reverseList(head);
    print (head);

    return 0;
}

