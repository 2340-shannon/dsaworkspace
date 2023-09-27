#include "stack.h"

// Initialize the stack
void init(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an item onto the stack
void push(Stack* stack, int item) {
    if (!is_full(stack)) {
        stack->top++;
        stack->data[stack->top] = item;
    } else {
        // Handle stack overflow error here (optional)
    }
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (!is_empty(stack)) {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    } else {
        // Handle stack underflow error here (optional)
        return -1; // You can choose to return a specific error value or use a different approach
    }
}