#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_STACK_SIZE 100

// Define a stack structure for integers
struct Stack {
    int items[MAX_STACK_SIZE];
    int top;
};

// Function prototypes
void initialize(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, int item);
int pop(struct Stack *stack);
char peek(struct Stack *stack);
int precedence(char operator);
void infixToPostfix(char infix[], char postfix[]);

#endif
