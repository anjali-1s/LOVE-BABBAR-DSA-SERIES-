// Write a program to implement a queue using array.
#include <iostream>
using namespace std;

class Queue
{
  public:
       int *arr;
       int front;
       int rear;
       int size;
  
  public:
       // making a queue constructor
       Queue()
       {
          size = 100;
          arr = new int[size];
          front = 0;
          rear = 0;
       }

       // check whether the queue is empty or not!
       bool IsEmpty()
       {
          if(rear == front)
          {
               cout<<"Queue is empty!"<<endl;
          }
          else {
               cout<<"Queue is not empty!"<<endl;
          }
       }

       // Enqueue the elements into  the Queue
       int Enqueue(int data)
       {
          if(rear == size)
          {
               cout<<"Queue is full can't enter elements!"<<endl;
          }
          else {
               arr[rear] = data;
               rear++;
          }
       }

       // Dequeue the elements from the Queue
       int Dequeue()
       {
          if(front == rear)
          {
               cout<<"Queue is empty!, can't dequeue!"<<endl;
          }
          else {
               int ans = arr[front];
               arr[front] = -1;
               front++;
               if(front == rear)
               {
                    front = 0;
                    rear = 0;
               }
               cout<<endl;
               return ans;
          }
       }

       // to print the queue
       void displayQueue()
       {
          if(rear == front)
          {
               cout<<"Queue is empty!"<<endl;
               return;
          }
          cout<<"The elements of the queue are:";
          for(int i = front; i<rear; i++)
          {
               cout<<arr[i]<<"\t";
          }
          cout<<endl;
          return;
       }
};

int main()
{
     Queue q;
     q.IsEmpty();
     cout<<endl;
     q.Enqueue(13);
     q.Enqueue(15);
     q.Enqueue(18);
     q.Enqueue(19);
     cout<<endl;
     q.displayQueue();
     q.Dequeue();
     q.displayQueue();
     return 0;
}