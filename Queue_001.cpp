// Write a program to implement a queue using STL.
#include <iostream>
#include <queue>
using namespace std;

void show(queue<int>q)
{
    cout<<"The elements of the queue are:"<<"\t";
    while(!q.empty())
    {
     cout<<q.front()<<"\t";
     q.pop();
    }
    cout<<endl;
}

int main()
{
     // Create a queue
     queue<int>q;
     q.push(17);
     q.push(14);
     q.push(15);
     q.push(16);

     // printing the size of queue
     cout<<"The size of the queue is :"<<q.size()<<endl;

     // printing the queue element
      show(q);
      
     // check whether the queue is empty or not
     if(q.empty())
     {
          cout<<"Queue is empty!";
     }
     else 
     {
          cout<<"Queue is not empty!";
     }
     cout<<endl;
     cout<<"The front element of the queue is:"<<q.front()<<endl;
     cout<<"The rear element of the queue is:"<<q.back()<<endl;

     q.pop();
     q.pop();
     show(q);
     cout<<"The size of the queue is:"<<q.size()<<endl;
}