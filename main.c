#include <stdio.h>
#include "stack.h"

// Main program
int main() {
    Stack myStack;
    init(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    return 0;
}