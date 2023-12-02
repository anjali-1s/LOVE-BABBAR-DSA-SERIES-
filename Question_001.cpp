// Write a c++ program to input and output a string and find its length.

#include <iostream>
#include <string>
using namespace std;

int getlength(char s[])
{
   int count = 0;
   for(int i = 0; s[i] != '\0'; i++)
   {
     count++;
   }
   cout<<"The length of the given string is:"<<"\t";
      return count;
}

int main()
{
    char s[] = "Anjali singh";
    cout<<s<<endl;
    cout<<getlength(s);
    return 0;
}