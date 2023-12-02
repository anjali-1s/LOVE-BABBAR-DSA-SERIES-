// write a program to insert an element at the bottom of the stack.
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st,int x)
{
     // base case
     if(st.empty())
     {
          st.push(x);
          return;
     }

     int num = st.top();
     st.pop();

     // recursive call
     solve(st,x);
     st.push(num);
}
int main()
{
     stack<int>st;
     st.push(12);
     st.push(19);
     st.push(56);
     st.push(34);
     
     solve(st,36);

     // printing stack after insertion
     while(!st.empty())
     {
          int ans = st.top();
          st.pop();
          cout<<ans<<" ";
     }
     return 0;
}
