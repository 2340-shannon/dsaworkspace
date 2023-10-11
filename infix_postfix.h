#ifndef INFIX_POSTFIX_CONVERTER_H
#define INFIX_POSTFIX_CONVERTER_H

#define MAX_STACK_SIZE 100

// Define a stack structure for characters
struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack);

// Function to check if the stack is empty
int isEmpty(struct Stack *stack);

// Function to push an item onto the stack
void push(struct Stack *stack, char item);

// Function to pop an item from the stack
char pop(struct Stack *stack);

// Function to get the top item of the stack without popping
char peek(struct Stack *stack);

// Function to determine the precedence of an operator
int precedence(char operator);

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]);

#endif /* INFIX_POSTFIX_CONVERTER_H */
