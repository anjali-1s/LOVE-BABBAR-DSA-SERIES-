// write a program to check a paranthesis is valid or not.
#include <iostream>
#include <stack>
using namespace std;

bool isvalidparanthesis(string str)
{
     stack<char>st;
     // taking the elements of string as an inpput
     for(int i = 0; i < str.length(); i++)
     {
          char ch = str[i];
          if(ch == '(' || ch == '{' || ch == '[')
          {
               st.push(ch);
          }
          else {
               if(!st.empty())
               {
                    char top = st.top();
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    {
                         st.pop();
                    }
                    else 
                         return false;
                    
          }
     else {
                 return false;
             }
         }
     }
     if(st.empty()) {
         return true;
     }
     else {
         return false;
     }
}

int main()
{
     string str = "{([])}";
     int ans = isvalidparanthesis(str);
     cout<<ans;
     return 0;
}