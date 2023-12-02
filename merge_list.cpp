// write a progarm to merge two sorted linked list
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

void InsertAtTail1 ( Node* &tail , int d ) {
       Node* temp = new Node(d) ;
       tail -> next = temp ;
       tail = temp ;
 }


void InsertAtTail2 ( Node* &tail , int d ) {
       Node* temp = new Node(d) ;
       tail -> next = temp ;
       tail = temp ;
 }

Node* solve(Node* head1, Node* head2) {
    Node* curr1 = head1;
    Node* next1 = curr1 -> next;
    Node* curr2 = head2;
    Node* next2 = curr2 -> next;
    while(next1 != NULL && curr2 != NULL) {
        if((curr2 -> data >= curr1 ->data) && curr2 -> data <= next1 -> data) {
            // step :1
            curr1 -> next = curr2;
            // step :2
            next2 = curr2 -> next;
            // step :3
            curr2 -> next = next1;
            // step :4
            curr1 = curr2;
            // step : 5
            curr2 = next2;
        }

        else {
            // go one list ahead in first list
            // curr1 and next1 ko aage bdha do
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return head1;
            }
        }

    }
    return head1;
}

Node* sortTwolist(Node* head1, Node* head2) {
    // if there is only one element
    if(head1 == NULL)
    return head2;
    if(head2 == NULL)
    return  head1;
    if(head1 ->data <= head2 -> data){
        solve(head1,head2);
    }
    else {
        return solve(head2,head1);
    }
return solve(head1,head2);
}
 int main() {
        Node* node1 = new Node(12);
        Node* tail = node1;
        cout<<"the first list is :";
        print(tail);
        InsertAtTail1(tail,24);
        print(tail);

        InsertAtTail1(tail,13);
        print(tail);

        InsertAtTail1(tail,21);
        print(tail);

        InsertAtTail1(tail,14);
        print(tail);

        cout<<endl;

    Node* node2 = new Node(40);
   // cout<<node2->data<<endl;
    Node* tail2 = node2;
    cout<<"the second list is:";
    print (tail2);
     
        InsertAtTail2(tail,90);
        print(tail);

        InsertAtTail2(tail,35);
        print(tail);

        InsertAtTail2(tail,64);
        print(tail);

        InsertAtTail2(tail,45);
        print(tail);
        cout<<endl;
        Node* head1 = node1;
        Node* head2 = node2;
        sortTwolist(head1,head2);
        print(tail);

       return 0;
 }