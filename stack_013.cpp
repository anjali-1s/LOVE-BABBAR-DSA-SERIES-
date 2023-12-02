// Largest rectangular area in histogram.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int>nextSmallerElement(vector<int>&arr,int n)
{
     stack<int>st;
     st.push(-1);

     vector<int>answer(n);

     for(int i = n-1; i >= 0; i--)
     {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
           st.pop();
       }

       answer[i] = st.top();
       st.push(i);
   }
   return answer;
   }

vector<int>previousElement(vector<int>&arr, int n)
 {
     stack<int>st;
     st.push(-1);

     vector<int>answer(n);

     for(int i = 0; i < n; i++)
     {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr){
           st.pop();
       }

       answer[i] = st.top();
       st.push(i);
   }
   return answer;
 }

int LargestArea(vector<int> height)
{
     int n = height.size();
     vector<int>next(n);
     next = nextSmallerElement(height,n);

     vector<int>previous(n);
     previous = previousElement(height,n);
      
      int area = 0;
     for(int i = 0; i < n; i++)
     {
          int l = height[i];
          if(next[i] == -1)
          {
            next[i] = n;
          }
         int b = next[i] - previous[i] - 1;

            int newArea = l * b;
            area = max(area,newArea);
     }
       return area;
}

int main()
{
     vector<int>height = {6,2,1,3,4,7,4,6,1,1};
     int ans = LargestArea(height);
     cout<<ans;
     return 0;
}