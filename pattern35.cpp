// write a program to print the following pattern ( for n = 5 ) :
/*            1 * * * * * * * * 1
              1 2 * * * * * * 2 1
              1 2 3 * * * * 3 2 1 
              1 2 3 4 * * 4 3 2 1 
              1 2 3 4 5 5 4 3 2 1
*/           
#include <iostream > 
using namespace std;
int main (){
    int n ;
    cout<<" enter the value of n :"<<endl;
    cin>>n;
    int i = 1;
    while ( i <= n){
        // part -------> 1
        int j = 1;
        while ( j <= i){
            cout<<j<<" ";
            j++;
        }
    // part --------> 2
      j = 1;
      while ( j <= ( 2 * n ) - ( 2 * i )){
        cout<<"*"<<" ";
        j++;
      }
      // part --------> 3
      j = i;
      while ( j >= 1 ){
        cout<<j<<" ";
        j--;
      }
      cout<<endl;
      i++;
    }
    return 0 ;
}
