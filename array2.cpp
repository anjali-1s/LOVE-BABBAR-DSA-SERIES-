// write  a program to find maximum ana minimum element
#include <iostream>
using namespace std;
int main() {
     int arr[] = {19,50,39,92,88};
     int n=5;
     int i,j;
     for( i=0; i<n; i++) {
        for( j=i+1; j<n-1; j++){
           if(arr[i] > arr[j]) {
            continue;
           }
        }
        
        }
        cout<<arr[i]<<endl;

     }
