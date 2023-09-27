#ifndef POSTFIX_EVAL_H
#define POSTFIX_EVAL_H

#define MAX_STACK_SIZE 100

struct Stack {
    int items[MAX_STACK_SIZE];
    int top;
};

void initialize(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, int item);
int pop(struct Stack *stack);
int evaluatePostfix(char postfix[]);

#endif /* POSTFIX_EVAL_H */
