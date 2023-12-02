// Write a program to implement deque using circular array.
#include <iostream>
using namespace std;
#define MAX 100

class Deque
{
   public:
         int arr[MAX];
         int front;
         int rear;
         int size;
   public:
         Deque(int size)
         {
            front = -1;
            rear = 0;
            this -> size = size;
         }

         // operations on deque
         void insertfront(int key);
         void insertrear(int key);
         void deletefront();
         void deleterear();
         bool isFull();
         bool isEmpty();
         int getfront();
         int getrear();
         
};
// check whether the deque is full or not
bool Deque :: isFull()
{
     return ((front == 0 && rear == size - 1) || front == rear + 1);
}

// check whether the deque is empty or not
bool Deque :: isEmpty()
{
     return (front == -1);
}

void Deque :: insertfront(int key)
{
      // check whether Deque if  full or not
    if (isFull()) {
        cout << "Overflow\n" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1;
 
    else // decrement front end by '1'
        front = front - 1;
 
    // insert current element into Deque
    arr[front] = key;
}

void Deque :: deletefront()
{
     // check whether Deque is empty or not
    if (isEmpty()) {
        cout << "Queue Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size - 1)
        front = 0;
 
    else // increment front by '1' to remove current
        // front value from Deque
        front = front + 1;
}

void Deque :: insertrear(int key)
{
     if (isFull()) {
        cout << " Overflow\n " << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size - 1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear + 1;
 
    // insert current element into Deque
    arr[rear] = key;
}

void Deque :: deleterear()
{
     if (isEmpty()) {
        cout << " Underflow\n" << endl;
        return;
    }
 
    // Deque has only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}

int Deque :: getfront()
{
     // check whether the deque id empty
     if(isEmpty())
     {
          cout<<"underflow"<<endl;
     }
      return arr[front];
}

int Deque :: getrear()
{
     // check whether the queue is empty
     if(isEmpty() || rear < 0)
     {
          cout<<"underflow!"<<endl;
          return -1;
     }
      return arr[rear];
}

int main()
{
     Deque DQ(5);

     cout<<"insert element at front end :"<<" ";
     DQ.insertfront(12);
     cout<<endl;
     cout<<"insert element at rear end :"<<" ";
     DQ.insertrear(15);
     DQ.insertrear(18);
     DQ.insertrear(17);
     cout<<endl;
     cout<<"get rear element of the queue :"<<DQ.getrear()<<endl;
     cout<<"get front element of the queue :"<<DQ.getfront()<<endl;

     DQ.deletefront();
     DQ.deleterear();

     cout<<"After deletion new rear is:"<<DQ.getrear()<<endl;
     cout<<"After deletion new front is:"<<DQ.getfront()<<endl;
     return 0;

}