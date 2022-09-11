#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack{
    //data members
private:
    int size;
    T *arr;
    int top;

    //methods
public:
     Stack(int size)
     {
         this->size = size;
         arr = new T[size];
         top = -1;
     }

     void push(T data)
     {
          if(top == size-1) {
              cout << "stack full" << endl;
              return;
          }
          top++;
          arr[top] = data;
     }

     void pop()
     {
         if(isEmpty())
         {
             cout<<"Stack is Empty"<<endl;
             return;
         }
         top--;
     }

     int peek(){
         if(isEmpty()) {
             cout << "Stack Underflow" << endl;
             return -1;
         }
         return arr[top];
     }

     bool isEmpty()
     {
         if(top==-1)
             return true;
         return false;
     }
};



int main() {

    int size;
    cout<<"Enter size of stack:";
    cin>>size;
    Stack<int> s(size);
    s.push(12);
    s.push(13);
    s.push(14);
    s.pop();

    if(s.isEmpty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Top Element: "<<s.peek()<<endl;


}
