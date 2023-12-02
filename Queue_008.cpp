// Write a program to find first negative integer in every window of size k.
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

         deque<int>dq;
         vector<int>ans;
                
    // process first k size window
        for(int i = 0; i<k; i++)
        {
            if(arr[i] < 0)
            {
                dq.push_back(i);
            }
        }
                
     // store answer of first k size window
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
                
     // process for remaining windows
        for(int i = k; i < n ; i++)
        {
            // removal
            if(!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }
                    
            // addition
              if(arr[i] < 0)
              {
                dq.push_back(i);
              }
                    
            // ans store
                if(dq.size() > 0)
                {
                    ans.push_back(arr[dq.front()]);
                }
                else 
                {
                        ans.push_back(0);
                }
                }
                  return ans;
 }

int main()
{
    vector<int>arr{-8,2,3,-6,10};
    int N = 5;
    int K = 2;
    vector<int>ans;
    ans = firstNegativeInteger(arr,K,N);
    for(auto it : ans)
    cout<<it<<" ";
    
    return 0;
}