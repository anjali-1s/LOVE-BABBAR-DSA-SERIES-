// Merge two binary max heaps
#include <iostream>
#include <vector>
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


// heapify function to create max heap---->>>
void heapify (vector <int> &arr,int n,int i) {
     int largest = i;
     int left = 2 * i + 1;
     int right = 2 * i + 2;

     if(left < n && arr[largest] < arr[left]) {
          largest = left;
     }

     if (right  < n && arr[largest] < arr[right]) {
          largest = right;
     }

     if (largest != i) {
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
     }
}

vector <int> Mergeheaps (vector<int> &h1, vector<int> &h2,int n, int m ) {
     // step 1: merge both arrays into one
      vector<int> ans;

      for (auto i : h1)
        ans.push_back(i);

     for (auto i : h2)
     ans.push_back(i);

     // step 2: building heap using merged array
     int n = ans.size();

     for (int i = n/2 - 1; i>0; i--) {
      heapify(ans,n,i);
     }

       return ans;
}


int main() { 
       Heap h1;
  
       h1.insert(10);
       h1.insert(5);
       h1.insert(6);
       h1.insert(2);
       int n = 4;
       h1.print();
       cout<<endl;

       Heap h2;

       h2.insert(12);
       h2.insert(7);
       h2.insert(9);
       int m = 3;
       h2.print();
       cout<<endl;

       vector<int> ans;
     ans = Mergeheaps(h1,h2,n,m);
     
       
       return 0;

}