// sum of factorial
#include <iostream>
using namespace std;

int sumfactorial(long long f) {
     if(f == 0)
        return 0;
        
        int digit = f % 10;
        return (digit + sumfactorial(f/10));
}

long long factorial(int num) {
     if(num <= 1)
        return 1;

        return num *factorial(num -1);
}

int main() {
     int n ;
     cout<<"Enter the number :"<<endl;
     cin>>n;
     
     cout<<"factorial of :" <<n<<" -> "<<factorial(n)<<endl;
     cout<<"sum of factorial is :"<<sumfactorial(factorial(n))<<endl;
     return 0;
     }

