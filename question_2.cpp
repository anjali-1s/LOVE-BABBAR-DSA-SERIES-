// Write a program to find the kth smallest and largest element in a heap

#include <iostream>
#include <queue>
using namespace std;

class Heap {
     public :
          int arr[100];
          int size = 0;

// constructors
Heap () {
     arr[0] = -1;
     size = 0;
}
// insertion in a heap ---->>>
     void insert (int val) {
          size++;
          int index = size;
          arr[index] = val;

          while (index > 1) {
               int parent = index / 2;
               if (arr[parent] < arr[index]) {
                    swap(arr[parent],arr[index]);
                    index = parent;
               }

               else {
                    return;
               }
          }
     }


// print the  heap
void print () {
     for (int i = 1; i <= size; i++) {
          cout <<arr[i] <<" ";
     }

     cout <<endl;
}

};


int kthsmallestElement (int arr[], int n, int k) {

     priority_queue <int> pq;

     // step 1 : create a k size max heap 

     for (int i = 0; i<k; i++) {
          pq.push(arr[i]);
     }

     // step 2 : push and pop with rest of the element 
     for (int i = k; i<n; i++) {
          if (arr[i] < pq.top()) {
               pq.pop();
               pq.push(arr[i]);
          }
     }

     // return ans
     int ans = pq.top();

     return ans;
}


int kthlargestElement (int arr[], int n, int k) {

     priority_queue <int> pq;

     // step 1: create a k size min heap
     for(int i = n/2; i>0; i--) {
       pq.push(arr[i]);
     }

     // step 2 : push and pop  with rest of the element
    for (int i = k; i<n; i++) {
     if (arr[i] > pq.top()) {
          pq.pop();
          pq.push(arr[i]);
     }
    }

    // return ans
    int ans = pq.top();

    return ans; 
}


int main () {
     Heap h;

     h.insert(7);
     h.insert(10);
     h.insert(4);
     h.insert(3);
     h.insert(20);
     h.insert(15);
     //int n = 7;
     h.print();

  int arr[6] = {7,10,4,3,20,15};
  int n = 6;
  
  cout <<"The kth smallest element of the given heap is :" <<kthsmallestElement(arr,n,4);
  cout <<endl;

  cout <<"The kth largest element of the given heap is :" <<kthlargestElement(arr,n,2);
  cout <<endl;

     return 0;
}