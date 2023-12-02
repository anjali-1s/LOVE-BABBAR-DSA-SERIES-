// electricity bill problem 
#include <iostream>
using namespace std;
int main() {
     int units, amount = 0;
     string name;
     cout <<"Enter the units consumed :"<<endl;
     cin>>units;
     
     if(units <= 300){
          amount = units * 90;
     }
     else if(units >= 100 && units <= 300){
          amount = amount + (units -100) * 80;
     }
     else if (units <= 100){
          amount = units * 50;
     }
     if (amount > 300){
          amount = amount + (amount / 100) *15;
     }
      
     cout<<"Enter the name:"<<endl;
     cin>>name;

     cout <<"The amount is :"<<amount<<" "<<"for the consumed units:"<<units<<" "<<"of the"<<" "<<name;
     return 0;
}
