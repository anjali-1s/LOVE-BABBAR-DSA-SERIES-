// Write a program to reverse first k elements of a queue.
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int>modifyQueue(queue<int>q,int k)
{
    // algo
    // step 1: pop first k element from Q and put into stack.
    stack<int>s;
    for(int i = 0; i<k; i++)
    {
     int val = q.front();
     q.pop();
     s.push(val);
    }

    // step 2: fetch from stack and push into queue.
    while(!s.empty())
    {
     int value = s.top();
     s.pop();
     q.push(value);
    }

    // step 3: fetch first (n-k) elements from Q and push back into Q.
     int t = q.size() - k;
     while(t--)
     {
          int val = q.front();
          q.pop();
          q.push(val);
     }
       return q;
}

int main()
{
     queue<int>q;
     q.push(1);
     q.push(2);
     q.push(3);
     q.push(4);
     q.push(5);
     int k = 3;

     queue<int>ans;
     ans = modifyQueue(q,k);
     
     cout<<"The queue before reversal:";
     while(!q.empty())
     {
          cout<<q.front()<<" ";
          q.pop();
     }
     cout<<endl;
     cout<<"The queue after reversal:";
     while(!ans.empty())
     {
          cout<<ans.front()<<" ";
          ans.pop();
     }
       return 0;
}