// Celebrity problem
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>>&m, int a, int b, int n)
{
     if(m[a][b] == 1)
        return true;
     else
        return false;
}

int findcelebrity(vector<vector<int>>&m, int n)
{
     // step 1: create a stack and push all elements into the stack
     stack<int>s;
     for(int i = 0; i < n; i++)
          s.push(i);
     
     // step 2: write s.size != 1, then take two elements A and B
     while(s.size() > 1)
     {
          int A = s.top();
          s.pop();
          int B = s.top();
          s.pop();
     
     // step 3: compare A and B
     if(knows(m,A,B,n))
       s.push(B);
     else 
       s.push(A);
     } 
      int ans = s.top();
     // step 4: Last remaining element in the stack is a potential candidate for being a celebrity
       int zerocount = 0;

     // step 5: verify the celebrity
     for(int i = 0; i < n; i++)
     {
          // verify row
          if(m[ans][i] == 0)
               zerocount++;
     }
          // all zeroes
          if(zerocount != n)
            return -1;

          // verify column
          bool colcheck = false;
          int onecount = 0;
     for(int i = 0; i < n; i++)
     {
          if(m[i][ans] == 1 )
            onecount++;
     }
          if(onecount != n-1)
            return -1;

       return ans;
}

int main()
 {
     vector<vector<int>>m ={{0,0,1,1,1},
                            {1,0,1,0,0},
                            {0,0,0,0,0},
                            {0,1,1,0,1},
                            {1,0,1,0,0}};
      int n = m.size();
      int ans = findcelebrity(m,n);
      cout<<ans;
      return 0;
}