// write a program to delete a middle element from stack.
#include <iostream>
#include <stack>
using namespace std;

int solve(stack<int> &inputStack, int count, int size)
{
     // base case
     if(count == size/2)
     {
          inputStack.pop();
          return 0;
     }

     int num = inputStack.top();
     inputStack.pop();

     // recursive call
     solve(inputStack,count + 1,size);
     inputStack.push(num);
}

int deleteMiddle(stack<int> &inputStack,int N)
{
     int count = 0;
     int ans = solve(inputStack,count,N);
     return ans;
}

int main()
{
     stack<int>inputStack;
     inputStack.push(21);
     inputStack.push(12);
     inputStack.push(13);
     
     int ans = deleteMiddle(inputStack,inputStack.size());
     
     // printing stack after deletion
     while(!inputStack.empty())
     {
          int ans = inputStack.top();
          inputStack.pop();
          cout<<ans<<" ";
     }
     return 0;
}
     