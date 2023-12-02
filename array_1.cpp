// reverse an array ----->>>>
#include <iostream>
using namespace std;
int main() {
    int arr[] = {12,34,23,10,16};
    int n = 5;
    int s=0;
    int e=n-1;
    while ( s<= e) {
        swap(arr[s] , arr[e]);
        s++;
        e--;
    }

    // printing array
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}