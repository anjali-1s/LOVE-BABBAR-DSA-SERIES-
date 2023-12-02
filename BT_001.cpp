// Write a program to implement binary tree.
#include <iostream>
#include <queue>
using namespace std;

class node
{
     public:
           int data;
           node* left;
           node* right;

           // constructor
           node(int d)
           {
               this -> data = d;
               this -> left = NULL;
               this -> right = NULL;
           }
};

node* builtTree(node* root)
{
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
      return NULL;
    }
      cout<<"Enter the data to insert in left :"<<data<<endl;
      root -> left = builtTree(root -> left);

      cout<<"Enter the data to insert in right :"<<data<<endl;
      root -> right = builtTree(root -> right);

      return root;
}

void levelOrderTraversal(node* root)
{
      queue<node*>q;
      q.push(root);   // first node
      q.push(NULL);

      while(!q.empty())
      {
          node* temp = q.front();
         
          q.pop();

          if(temp == NULL) // it means purana level complete ho chuka h
          {
              cout<<endl;
          
              if(!q.empty())
              {
               q.push(NULL);   // queue m elements child nodes
              }
          
          }
          else {
               cout<<temp -> data<<" ";
             if(temp -> left)
             {
               q.push(temp -> left);
             } 

             if(temp -> right)
             {
               q.push(temp -> right);
             }
      }
      }
}

int main()
{
     node* root = NULL;

     // creating a tree
     root = builtTree(root);

     // level order traversal
     levelOrderTraversal(root);
     return 0;
}