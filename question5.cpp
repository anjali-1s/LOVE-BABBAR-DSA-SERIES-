// reverse number
#include <iostream>
using namespace std;

int main() {
       int num;

       cout<<"Enter the number :"<<endl;
       cin>>num;
       int ans = 0;
       while (num != 0){
          int digit = num % 10;
          ans = (ans * 10) + digit;
          num = num/10;
       }
       cout <<"The reverse number is :"<<ans;
       return 0;
}