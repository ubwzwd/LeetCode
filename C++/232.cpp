/*
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
private:
    stack<int>* data_stack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        data_stack = new stack<int>;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // import a temp stack to store the preview data
        stack<int> temp_stack;
        while(!data_stack->empty())
        {
            temp_stack.push(data_stack->top());
            data_stack->pop();
        }
        data_stack->push(x);
        while(!temp_stack.empty())
        {
            data_stack->push(temp_stack.top());
            temp_stack.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!data_stack->empty())
        {
            int front_element = data_stack->top();
            data_stack->pop();
            return front_element;
        }
        else return NULL;
    }
    
    /** Get the front element. */
    int peek() {
        return data_stack->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data_stack->empty();
    }

    ~MyQueue()
    {
        delete data_stack;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */