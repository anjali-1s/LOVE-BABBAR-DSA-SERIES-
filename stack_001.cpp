// stack implementation
#include <iostream>
#include <stack>
using namespace std;

// printing a stack
void printStack(stack<int>& s)
{
     // check if stack is empty
     if(s.empty()) 
     {
          return ;
     }
     int x = s.top();
     s.pop();

     printStack(s);
     cout<<x<<endl;

     s.push(x);
}

int main() 
{
   // creation of stack
     stack<int>s;

   // push operation
    s.push(12);
    s.push(24);
    s.pop();
    
    s.push(22);
    s.push(17);
    printStack(s);

    cout<<"The top element of the created stack is :"<<s.top()<<endl;


    if(s.empty())
    {
     return 0;
    }
    else 
    {
     cout<<"stack is not empty!"<<endl;
    }
    
    return 0; 
}