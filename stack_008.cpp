// write a program to reverse a stack using recursion.
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &stack,int x)
{
     // base case
     if(stack.empty())
     {
          stack.push(x);
          return;
     }

     int num = stack.top();
     stack.pop();
     insertAtBottom(stack,x);
     stack.push(num);
}

void reverseStack(stack<int>&stack) 
{
     // base case
     if(stack.empty())
     {
          return;
     }

     int num = stack.top();
     stack.pop();

     reverseStack(stack);
     insertAtBottom(stack,num);
}

int main()
{
     stack<int> stack;
     stack.push(10);
     stack.push(34);
     stack.push(65);
     stack.push(29);
     stack.push(45);
     
     reverseStack(stack);

     // printing the stack after reverse the stack
     while(!stack.empty())
     {
          int ans = stack.top();
          stack.pop();
          cout<<ans<<" ";
     }
     return 0;
}