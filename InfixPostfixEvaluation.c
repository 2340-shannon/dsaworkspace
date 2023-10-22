#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixPostfixEvaluation.h"


// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, int item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to get the top item of the stack without popping
char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character for an empty stack
    }
    return stack->items[stack->top];
}

// Function to determine the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    
    int i, j;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isdigit(token)) {
            // If it's a digit, add it to the output
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add a space to separate operands
            i--; // Decrement i to account for the extra increment in the while loop
        } else if (token == '(') {
            // If it's an open parenthesis, push it onto the stack
            push(&stack, token);
        } else if (token == ')') {
            // If it's a closing parenthesis, pop operators from the stack
            while (peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' '; // Add a space to separate operators
            }
            pop(&stack); // Pop the '('
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            // If it's an operator, pop operators from the stack with higher or equal precedence
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' '; // Add a space to separate operators
            }
            push(&stack, token);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' '; // Add a space to separate operators
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}


// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            // Skip spaces
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {
            // Parse multi-digit numbers and push them onto the stack
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&stack, num);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            // If it's an operator, pop the top two operands from the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            // Perform the operation and push the result back onto the stack
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
            }
            i++;
        } else {
            printf("Invalid character in expression: %c\n", postfix[i]);
            exit(1);
        }
    }

    // The final result is at the top of the stack
    return pop(&stack);
}


