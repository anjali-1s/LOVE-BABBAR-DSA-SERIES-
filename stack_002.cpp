// write a program to create a stack class and perform all stack operations on it.
#include <iostream>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public :
       int a[MAX];  //maximum size of a stack
       
       // creating a constructor
       Stack() {
          top = -1;
       }

       // method for push operation
       bool push(int x);

       // method for pop
       int pop();
       
       // method for peek or top element
       int peek();

       // method to check is stack empty?
       bool isEmpty();
};

bool Stack :: push(int x)
{
     if(top >= (MAX-1)) {
          cout<<"Stack overflow";
          return false;
     }
     else {
          a[++top] = x;
          cout<<x<<"\t pushed into stack \n";
          return true;
     }
}

int Stack :: pop()
{
     if(top < 0) {
          cout<<"Stack underflow !"<<endl;
          return 0;
     }
     else {
          int x = a[top--];
          return x;
     }
}

int Stack :: peek()
{
     if(top < 0) {
        cout<<"Stack is empty!";
        return 0;
     }
     else {
          int x = a[top];
          return x;
     }
}

bool Stack :: isEmpty()
{
     return (top < 0);
}

// Driver program to perform these all operations
int main() {
       Stack s;
       
       s.push(10);
       s.push(24);
       s.push(19);

      cout<<s.pop()<<"\t Value popped from stack ! \n"<<endl;
      cout<<"Top element of the stack is : \t" <<s.peek();
      cout<<"\n"<<s.isEmpty()<<endl;

      // printing all the values of stack
      while(!s.isEmpty()) 
      {
          cout<<s.peek()<<" ";
          s.pop();
      }
       return 0;
}