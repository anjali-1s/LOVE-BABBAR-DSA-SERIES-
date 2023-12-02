// next smaller element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int>smaller (vector<int> &arr, int n)
{
   stack<int>s;
   s.push(-1);

   vector<int>ans(n);

   for(int i=n-1; i>= 0; i--) {
       int curr = arr[i];
       while(s.top() >= curr){
           s.pop();
       }

       ans[i] = s.top();
       s.push(curr);
   }
   return ans;
}

int main()
{
     vector<int>arr = {1,0,2,1,2,0};
     int n = 4;
     vector<int>ans(n);
     // printing the vector array
     for (auto it = arr.begin();
             it != arr.end(); it++) {
            cout << *it << ' ';
             }
     cout<<endl<<endl;
   // printing the answer array
    ans = smaller(arr,n);
    for (auto it = ans.begin();
             it != ans.end(); it++) {
            cout << *it << ' ';
             }

     return 0;
}