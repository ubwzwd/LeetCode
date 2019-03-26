/*
225. Implement Stack using Queues

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int>* data_queue;
    /* in the queue, store the data from bottom to top. So we can use pop to get the head element as if we get the element on the top of stack
public:
    /** Initialize your data structure here. */
    MyStack() {
        data_queue = new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // here we need a new queue to store the previews queue, so that we can store the newest element to the bottom
        queue<int> temp_queue;
        // move all the elements to temp queue, empty the data queue
        while(!data_queue->empty())
        {
            temp_queue.push(data_queue->front());
            data_queue->pop();
        }
        // store the new element
        data_queue->push(x);
        // return all the elements back to data queue
        while(!temp_queue.empty()){
            data_queue->push(temp_queue.front());
            temp_queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!data_queue->empty())
        {
            data_queue->pop();
        }
    }
    
    /** Get the top element. */
    int top() {
        if(!data_queue->empty())
        {
            return data_queue->front();
        }
        else return NULL;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(data_queue->empty())
        {
            return true;
        }
        else return false;
    }
};