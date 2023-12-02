// implementing 2 stacks in an array
#include <iostream>
#include <stack>
using namespace std;

class TwoStack {
     int top1;
     int top2;
     int *arr;
     int size;

public :
        TwoStack(int s) {
          this -> size = s;
          top1 = -1;
          top2 = s;
          arr = new int[s];
        }

        // push in stack 1
        void push1(int num) {
          if(top2 - top1 > 1) {
               top1++;
               arr[top1] = num;
          }
        }

        // push in stack 2
        void push2(int num) {
          if(top2 - top1 > 1) {
               top2--;
               arr[top2] = num;
          }
        }

        // pop from stack 1 and return the popped element
        int pop1() {
          if (top1 >= 0) {
               int ans = arr[top1];
               top1--;
               return ans;
          }
          else {
                return -1;
          }
        }

        // pop from stack 2 and return the popped element
        int pop2() {
          if(top2 < size) {
               int ans = arr[top2];
               top2++;
               return ans;
          }
          else {
               return -1;
          }
        }

};

int main() {
     TwoStack s(5);
     s.push1(12);
     s.push1(23);
     s.push1(24);
     s.push1(35);

     cout<<"popped element from stack is :"<<s.pop1()<<endl;
     cout<<"popped element from stack is :"<<s.pop1()<<endl;
     
     s.push2(24);
     s.push2(39);
     cout<<"popped element from stack is :"<<s.pop2()<<endl;
      
      return 0;
}