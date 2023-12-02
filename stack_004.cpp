// write a program to reverse a string using a stack.
#include <iostream>
#include <stack>
using namespace std;

int main() 
{
     string str;
     cout<<"Enter the string :"<<endl;
     getline(cin,str);

     // step 1: creating a stack and taking input from string
     // creating a stack
     stack<char>s;
     for(int i = 0; i < str.length(); i++)
     {
          char ch = str[i];
          s.push(ch);
     }
     // step 2: creating a answer string
     string ans =" ";

     // step 3: pop up the stack's top elements and push it into answer string
     while(!s.empty())
     {
          char letters = s.top();
          ans.push_back(letters);
          s.pop();
     }
     // step 4: print the answer string 
      cout<<"The reverse string is :"<<"\t"<<ans;
      return 0;

}