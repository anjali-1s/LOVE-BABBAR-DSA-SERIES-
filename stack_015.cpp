// max rectangle in binary matrix with all 1's.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define R 4
#define C 4

vector<int>nextSmaller(vector<int>&arr)
{
      stack<int>st;
      st.push(-1);
      
      vector<int>ans(n);
      for(int i = n-1; i >= 0; i--)
      {   
          int curr = arr[i];
          while(st.top() != -1 && arr[st.top()] >= curr){
          st.pop();
          }
          ans[i] = st.top();
          st.push(i);
      }
        return ans;
  }
  
  vector<int>previousElement(vector<int>&arr)
  {
      stack<int>st;
      st.push(-1);
      
      vector<int>ans(n);
      for(int i= 0; i < n; i++)
      {
          int curr = arr[i];
          while(st.top() != -1 && arr[st.top()] >= curr){
          st.pop();
          }
          ans[i] = st.top();
          st.push(i);
      }
         return ans;
}
  
  
int LargestArea(int arr[])
{
         vector<int>next = nextSmaller(arr);
         vector<int>prev = previousElement(arr);
         
         int area = 0;
         for(int i = 0; i < R; i++)
         {
             int length = arr[i];
             if(next[i] == -1)
             next[i] = R;
             
             int breadth = next[i] - prev[i] - 1;
             int Newarea = length * breadth;
             area = max(area,Newarea);
         }
            return area;
}

int maxArea(int M[][C]) 
{
        int area = LargestArea(M[0]);
        for(int i = 1; i <R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(M[i][j])
                    M[i][j] = M[i][j] + M[i-1][j];
            }
               area = max(area,LargestArea(M[i]));
        }
          return area;
}

int main()
{
    int M[][C] = {{0,1,1,0},
                  {1,1,1,1},
                  {1,1,1,1},
                  {1,1,0,0}};
     int ans = maxArea(M);
     cout<<ans;   
     return 0;
}