#ifndef INFIXPOSTFIXEVALUATION_H
#define INFIXPOSTFIXEVALUATION_H

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
int peek(struct Stack *stack);
int precedence(char operator);
void infixToPostfix(char infix[], char postfix[]);
int evaluatePostfix(char postfix[]);

#endif // INFIXPOSTFIXEVALUATION_H