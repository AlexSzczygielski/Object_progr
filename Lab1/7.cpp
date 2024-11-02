#include <iostream>
using namespace std;

class Stack
{
    private:
        int* array; //dynamic array, storing data
        int top;
        int m_capacity;
        
    public:
        //constructor (size)
        Stack(int capacity)
        {
            m_capacity = capacity;
            array = new int[capacity]();
            top = -1; 
        }
        
        //destructor
        ~Stack()
        {
            delete[] array;
        }
        
        void push(int data)
        {
            if(top == m_capacity - 1)
            {
                cout << "stack overflow!" << endl;
            }
            else
            {
                array[++top] = data;
            
                cout << "data pushed: " << data << endl;
            }
        }
        
        void pop()
        {
            if(top == -1)
            {
                cout << "stack underflow!" << endl;
            }
            else
            {
                int data = array[top--];
            
                cout << "data popped: " << data << endl;
            }
        }
};

int main()
{
  Stack stack(4);
  
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  
  //demonstrate overflow
  stack.push(1);
  
  stack.pop();
  stack.push(4);
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  
  //demonstrate underflow
  stack.pop();

  return 0;  
}
