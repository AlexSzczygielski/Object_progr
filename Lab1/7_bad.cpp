#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;           // Dynamic array to store elements
    int capacity;       // Current capacity of the stack
    int top;            // Index of the top element

public:
    // Constructor to initialize stack
    Stack(int size = 10) {
        arr = new int[size];  // Allocate memory dynamically
        capacity = size;
        top = -1;  // Empty stack, so top is set to -1
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;  // Free the allocated memory
    }

    // Function to add an element to the stack
    void push(int element) {
        // Check if the stack is full, if yes, resize
        if (top == capacity - 1) {
            resize();
        }
        arr[++top] = element;  // Increment top and then add the element
    }

    // Function to remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top--];  // Return the top element and decrement top
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Function to get the size of the stack
    int size() const {
        return top + 1;
    }

    // Function to get the top element without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }

private:
    // Function to resize the stack dynamically when it is full
    void resize() {
        cout << "Resizing stack from " << capacity << " to " << capacity * 2 << endl;
        capacity *= 2;  // Double the size of the array
        int* newArr = new int[capacity];  // Allocate a new larger array

        // Copy the old elements to the new array
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;  // Free the old array memory
        arr = newArr;  // Assign the new array to arr
    }
};

int main() {
    Stack stack(5);  // Create a stack with an initial capacity of 5

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Pushing more elements to trigger resizing
    stack.push(60);

    // Pop elements from the stack
    cout << "Popped element: " << stack.pop() << endl;  // 60
    cout << "Popped element: " << stack.pop() << endl;  // 50

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;  // 40

    // Stack size
    cout << "Stack size: " << stack.size() << endl;  // 3

    return 0;
}
