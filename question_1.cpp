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

void deleteFromHeap () {
      if (size == 0) {
      cout <<"Nothing to print!" << endl;
      return;
}

// step 1: last node ko root node m daalo
  arr[1] =  arr[size];

// step 2: delete last node
  size--;

// step 3: take root node to its correct position 
  int i = 1;

  while (i < size) {
     int leftindex = 2 * i;
     int rightindex = 2 * i + 1;

     if (leftindex < size && arr[i] < arr[leftindex]) {
          swap(arr[i],arr[leftindex]);
          i = leftindex;
     }

     else if (rightindex < size && arr[i] < arr[rightindex]) {
               swap (arr[i],arr[rightindex]);
               i = rightindex;
           }

     else {
          return;
     }
  }
}

};

void heapify (int arr[], int n, int i) {
     int largest = i;
     int left = 2 * i;
     int right = 2 * i + 1;

     if (left < n && arr [largest] < arr[left]) {
          largest = left;
     }

     if (right < n && arr[largest] < arr[right]) {
          largest = right;
     }

     if (largest != i) {
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
     }
}

// min heap
void minheapify (int arr[], int n, int i) {
      int smallest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;

     if (left < n && arr[smallest] > arr[left]) {
          smallest = left;
     }

     if (right < n && arr[smallest] > arr[right]) {
          smallest = right;
     }

    if (smallest != i) {
     swap(arr[smallest] , arr[i]);
     minheapify (arr,n,smallest);
    }
}

// Heap sort
void heapsort (int arr[],int size) {
     int t = size;

     while (t > 1) {
   // step 1 : swapping of root node to last node
   swap(arr[size],arr[1]);
   size--;

  // step 2 : root node ko correct position pr daale
    heapify(arr,size,1);
     }
}

int main () {
          Heap h;

          h.insert(20);
          h.insert(78);
          h.insert(12);
          h.insert(18);

cout <<"The resultant heap is:" << endl;
          h.print();

 /*    
          h.deleteFromHeap();
          h.deleteFromHeap();
          h.deleteFromHeap();
          h.deleteFromHeap();
          h.print();
          h.deleteFromHeap();
          h.print();
  */

      int arr[6] = {-1,12,34,26,91,29};
      int n = 6;

      for (int i = n/2; i > 0; i--) {
          heapify(arr,n,i);
      }

      cout << "Printing the max heap :" << endl;

      for (int i = 1; i<n; i++){
          cout <<arr[i] <<" ";
      }

      cout << endl;

      for (int i = n/2; i > 0; i--) {
          heapify(arr,n,i);
      }

      cout << "Printing the min heap :" << endl;

      for (int i = 1; i<n; i++){
          cout <<arr[i] <<" ";
      }

      cout << endl;

 //cout<<"using heap sort algo :"<<endl;
   // heapsort(arr,n);
   // h.print();

   
   cout <<"using priority queue" << endl;

   // max heap
   priority_queue <int> pq;

   pq.push(70);
   pq.push(60);
   pq.push(55);
   pq.push(45);
   pq.push(50);
   
   cout <<"Element at top :"<<pq.top() << endl;
   cout<<"The size of the heap is :" <<pq.size()<<endl;;
   cout <<"Element to be popped :"<<endl;
   pq.pop();
  cout<<"The size of the heap is :" << pq.size()<<endl;

  if(pq.empty()) {
     cout <<"pq is empty !"<<endl;
  }

  else {
     cout <<"pq is not empty!"<<endl;
  }


 // min heap
 priority_queue <int,vector <int>, greater <int> >minheap;  

  minheap.push(4);
  minheap.push(2);
  minheap.push(5);
  minheap.push(3);

  cout <<"The top of the min heap is :" << minheap.top() <<endl;
  cout <<"The size of the minheap is :"<<minheap.size()<<endl;
  minheap.pop();
  cout <<"The size of the minheap is :"<<minheap.size() <<endl;
      return 0;
}