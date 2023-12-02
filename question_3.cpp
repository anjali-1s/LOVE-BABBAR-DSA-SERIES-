// check a binary tree is heap or not
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
     public:

     int data;
     Node* left;
     Node* right;

     Node(int d){
          int data = d;
          left = NULL;
          right = NULL;
     }
};

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

 Node* buildTree (Node* root) {
      cout <<"Enter the data :" <<endl;
      int data;
      cin>>data;

       root = new Node(data);

      if (data == -1) {
        return NULL;
      }

      cout <<"Enter data for inserting in left" << data<<endl;
      root -> left = buildTree(root -> left);

      cout <<"Enter data for inserting in right" <<data<<endl;
      root -> right = buildTree(root -> right);

      return root;
 }

 int countnode (Node* root) {
     // base case 
     if (root == NULL) {
          return 0;
     }

     int ans = 1 + countnode (root -> left) + countnode (root -> right);

     return ans;
}

bool isCBT (Node* root, int index, int cnt) {
      // base case
      if (root == NULL)
      return true;
      
      if (index >= cnt){
          return false;
      }
      
      else {
          bool left = isCBT(root -> left , 2 * index + 1, cnt);
          bool right = isCBT(root -> right, 2 * index + 2,cnt);
          
          return (left && right);
      }
     //  return (left && right);
}

bool ismaxorder (Node* root) {
     // leaf node 
      if (root -> left == NULL && root -> right == NULL) {
          return true;
      }
      
      
      if (root -> right == NULL) {
          return (root -> data > root -> left -> data);
      }
      
      else {
          bool left = ismaxorder (root ->left);
          bool right = ismaxorder(root -> right);
          
          return (left && right && (root -> data > root -> left -> data  &&  root -> data > root -> right -> data));
      }
         //return (left && right && ((root -> data > root -> left -> data) && (root -> data > root -> right -> data)));
}


bool isheap (Node* root) {
     int index = 0;
     int totalcount = countnode (root);

     if (isCBT(root,index,totalcount) && ismaxorder(root)) {
          return true;
     } 

     else {
          return false;
     }
}


int main () {

     Heap h;

      h.insert(97);
      h.insert(46);
      h.insert(37);
      h.insert(12);
      h.insert(3);
      h.insert(7);
      h.insert(31);
      h.insert(6);
      h.insert(9);

      h.print();

      Node* root = NULL;
      root = buildTree(root);
      
      bool ans = isheap(root);
      cout <<"the result is :"<<ans<<endl;;

     return 0;
}