/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <stack>
using namespace std;

// The main idea is to use another stack to store the min for every stage.
class MinStack {
private:
    stack<int>* data_stack;
    stack<int>* min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        data_stack = new stack<int>;
        min_stack = new stack<int>;
    }
    
    void push(int x) {
        if(data_stack->empty())
        {
            data_stack->push(x);
            min_stack->push(x);
        }
        else
        {
            data_stack->push(x);
            int current_min = min_stack->top();
            if(x<current_min)
            {
                min_stack->push(x);
            }
            else min_stack->push(current_min);
        }
    }
    
    void pop() {
        data_stack->pop();
        min_stack->pop();
    }
    
    int top() {
        if(!data_stack->empty())
        {
            return data_stack->top();
        }
        else return NULL;
    }
    
    int getMin() {
        if(!data_stack->empty())
        {
            return min_stack->top();
        }
        else return NULL;
    }

    ~MinStack()
    {
        delete data_stack, min_stack;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */