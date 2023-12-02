// Write a program to reverse a queue.
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reverseQueue(queue<int>& Queue)
{
     //step 1: pop the element from queue and push it into stack
     stack<int>st;
     while(!Queue.empty())
     {
          int element = Queue.front();
          Queue.pop();
          st.push(element);
     }
     
     //step 2: pop the element from stack and push it into queue
     while(!st.empty())
     {
          int element = st.top();
          st.pop();
          Queue.push(element);
     }
}

int main()
{
     queue<int>Queue;
     Queue.push(17);
     Queue.push(18);
     Queue.push(14);
     Queue.push(12);
     Queue.push(10);

     cout<<"The queue before reversal : \t";
     cout<<endl;
     cout<<"The queue after reversal : \t";
     reverseQueue(Queue);
     Print(Queue);

     return 0;
}