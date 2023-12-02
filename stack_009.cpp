// write a program to sort a stack.
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st,int data){
     // base case
     if(st.empty() || (!st.empty() && st.top() <= data))
     {
          st.push(data);
          return;
     }
     int top = st.top();
     st.pop();
     insertSorted(st,data);
     st.push(top);
}

void sortstack(stack<int> &st)
{
     if(st.empty())
     {
          return;
     }
     int top = st.top();
     st.pop();

     sortstack(st);
     insertSorted(st,top);
}

int main()
{
     stack<int>st;
     st.push(5);
     st.push(-2);
     st.push(9);
     st.push(-7);
     st.push(3);
     
     sortstack(st);

     // printing the stack
     while(!st.empty())
     {
          int ans = st.top();
          st.pop();
          cout<<ans<<" ";
     }
     return 0;
}