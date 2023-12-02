// Redundant brackets.
#include <iostream>
#include <stack>
using namespace std;

bool RedundantBracket(string str)
{
      stack<char>st;

      // step 1:
      for(int i = 0; i < str.length(); i++)
      {
          bool redundancy = true;
          char ch = str[i];

      // step 2:
      if(ch == '(' || ch == '+' || ch == '-'|| ch == '*'|| ch == '/')
      {
           st.push(ch);
      }
      else 
      {
          // step 3:
          if(ch == ')')
          {
           // step 3.1:
           while(st.top() != '(')
           {
               char top = st.top();

               // step 3.2:
               if(top == '+' || top == '-' || top == '*' || top == '/')
                  redundancy = false;

                  // step 4:
                  st.pop();
           }
           if(redundancy == true)        
               return false;
           
           // step 5:
           st.pop();
           }
          }
      }
         // step 6:
      return true;
}

int main()
{
     string str = "((a+b))";

     int ans =  RedundantBracket(str);
     cout<<ans;
     return 0;
}