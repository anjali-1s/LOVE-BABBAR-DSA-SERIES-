// Write a program to implement a queue using linked list.
#include <iostream>
using namespace std;

class QNode
{
   public:
        int data;
        QNode* next;

        // constructor
        QNode(int d)
        {
          data = d;
          next = NULL;
        }
};

class Queue
{
   public:
          QNode *rear;
          QNode *front;
     
     //constructor
     Queue()
     {
          front = rear = NULL;
     }

     // Enqueue the element into the Queue
     void EnQueue(int d)
     {
          QNode *temp = new QNode(d);
          // if queue list is empty
          if(rear == 0)
          {
               front = rear = temp;
          }
          // if not
          rear -> next = temp;
          rear = temp;
          cout<<endl;
     }

     // DeQueue the element from the queue list
     void DeQueue()
     {    
          // if Queue is empty
          if(front == NULL)
          {
               cout<<"The queue is empty!"<<endl;
               return;
          }
          QNode* temp = front;
          temp = temp -> next;

          // if front becomes null, then rear also becomes null
          if(front == NULL)
             rear = NULL;
          
          delete(temp);
          cout<<endl;
     }

     // Display the queue
     void display()
     {
          if(front == NULL)
        cout<<"\n Queue is Empty"<<endl;
    else
    {
        QNode *temp = front;
        while(temp->next != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp -> next;
        }
        cout<<temp->data<<" ";
     }
          cout<<endl;
     }

     // printing the size of queue
void QueueSize()
  {
     int count=0;
    if(front==NULL){
        cout<<"\n Queue is Empty!\n"<<endl;
        return ;
    }
    else
    {
        
        QNode *temp = front;
        while(temp->next != NULL)
        {
            count++;
            temp = temp -> next;
        }
        cout<<"Size of the queue is:"<<count+1;
    }
    cout<<endl;
    return ;
}

};

int main()
{
     Queue Q;
     Q.EnQueue(12);
     Q.EnQueue(13);
     Q.EnQueue(34);
     Q.EnQueue(28);
     Q.display();
     Q.DeQueue();
     cout << "Queue Front : " << ((Q.front != NULL) ? (Q.front)->data : -1)<< endl;
     cout << "Queue Rear : " << ((Q.rear != NULL) ? (Q.rear)->data : -1);
     cout<<endl;
     cout<<"The size of the queue is:";
     Q.QueueSize();
     return 0;
}
