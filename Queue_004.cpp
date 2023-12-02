// Write a program to implement a circular queue using array.
#include <iostream>
using namespace std;

class CircularQueue
{
   public :
        int *arr;
        int front;
        int rear;
        int size;

   public :
        CircularQueue(int n)
        {
          size = n;
          arr = new int[size];
          rear = front = -1;
        }

   // to push an element inside a circular queue
   bool EnQueue(int value)
   {
     if((front == 0 && rear == size -1) || (rear == (front -1) % (size - 1)))
     {
          cout<<"Queue is full!"<<endl;
          return false;
     }
      
      // if first element to push,then
     else if(front == -1){
               front = rear = 0;
               arr[rear] = value;
     }

     else if(rear == size - 1 && front != 0)
     {
          rear = 0;
          arr[rear] = value;
     }

     else {
          rear++;
          arr[rear] = value;
     }
        arr[rear] = value;
        return true;
   }

   // to pop an element from a queue
   int DeQueue()
   {
     if(front == -1)
     {
          cout<<"Queue is empty!"<<endl;
          return -1;
     }

     int ans = arr[front];
     arr[front] = -1;
     if(front == rear) // single element to pop
     {
          front = rear = -1;
     }
     else if(front == size -1)
     {

          front = 0;  // to maintain cyclic nature
     }

     else {
          front++;
     }
        return ans;
   }

   // to display the queue
   void Display()
   {
     if (front == -1)
    {
        cout<<"Queue is Empty \n";
        return;
    }
    cout<<"Elements in Circular Queue are: \t";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<"\t";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<"\t";
 
        for (int i = 0; i <= rear; i++)
           cout<<arr[i]<<"\t";
   }
   }
};


int main()
{
       CircularQueue  CQ(5);
       CQ.EnQueue(12);
       CQ.EnQueue(14);
       CQ.EnQueue(16);
       CQ.Display();
       cout<<endl;
       cout<<"Deleted elements are : \t"<<CQ.DeQueue()<<endl;
       cout<<"Deleted elements are : \t"<<CQ.DeQueue()<<endl;
       cout<<"Deleted elements are : \t"<<CQ.DeQueue()<<endl;
       CQ.Display();
       return 0;
 }