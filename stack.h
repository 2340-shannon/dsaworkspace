#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack
#define MAX_SIZE 100

// Structure to represent the stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void init(Stack* stack);
int is_empty(Stack* stack);
int is_full(Stack* stack);
//void push(Stack* stack, int item);
//int pop(Stack* stack);
#endif // STACK_H