#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Define a stack structure for characters
struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack *stack) {
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

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    
    int i, j;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isdigit(token)) {
            // If it's a digit, add it to the output
            postfix[j++] = token;
            while (isdigit(infix[i+1])) {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' '; // Add a space to separate operands
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

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
