#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Define a stack structure for integers
struct Stack {
    int items[MAX_STACK_SIZE];
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

int main() {
    char postfix[100];
    int result;

    printf("Enter a postfix expression: ");
    scanf("%[^\n]", postfix); // Read the entire line including spaces

    result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}