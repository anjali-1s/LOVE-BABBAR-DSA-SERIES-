// Write a program to implement double - ended queue using STL.
#include <iostream>
#include <deque>
using namespace std;

void showDQ(deque<int>DQ)
{
     deque<int> :: iterator it;
     for(it = DQ.begin(); it != DQ.end(); ++it)
     cout<<'\t'<<*it;
     cout<<endl;
}

int main()
{
     deque<int>DQ;
     DQ.push_back(18);
     DQ.push_front(16);
     DQ.push_back(17);
     DQ.push_front(12);

     cout<<"The deque DQ is :";
     showDQ(DQ);

     cout<<"\nThe size of the DQ is :"<<" "<<DQ.size()<<endl;
     cout<<"The max size of the DQ is :"<<" "<<DQ.max_size()<<endl;
     cout<<"The element at :"<<" "<<DQ.at(2)<<endl;
     cout<<"The front element of the deque is :"<<" "<<DQ.front()<<endl;
     cout<<"The back element of the deque is :"<<" "<<DQ.back()<<endl;

     cout<<"pop out the front element of the deque"<<" ";
     DQ.pop_front();
     cout<<endl;
     showDQ(DQ);

     cout<<"pop out the back element of the deque"<<" ";
     DQ.pop_back();
     cout<<endl;
     showDQ(DQ);
     return 0;
}