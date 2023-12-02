// singly linked list ------->>>>

#include <iostream>
using namespace std;

class Node {

    public :
           int data;
           Node* next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead (Node* Head, int data) {
       // create a new node 
       Node* temp = new Node(10);
       temp->next = Head;
       Head = temp;
}

void print (Node* &Head) {
    Node* temp = Head;

    // current node print -->>
    while (temp != NULL) {
        cout<<temp->data;
        temp = temp->next;
    }
}


int main() {
    Node* node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
        

        
    
    Node* Head = node1;
    Node* tail =node1;
    print(Head);



    return 0;
}