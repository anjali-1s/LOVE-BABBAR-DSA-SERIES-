// Write a java program to reverse a string.
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void reverse(string &S)
{
     int n = S.length();
     int s = 0;
     int e = n - 1;
     while(s <= e)
     {
          swap(S[s++],S[e--]);
     }
}

int main()
{
     string S ;
     cin>>S;
     cout<<S<<endl;
     reverse(S);
     cout<<S<<endl;
     return 0;
}