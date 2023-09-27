#include <stdio.h>
#include "stack.h"

// Main program
int main() {
    Stack myStack;
    init(&myStack);
    int choice, item;

    /* // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Pop elements from the stack and print them
    while (!is_empty(&myStack)) {
        int item = pop(&myStack);
        printf("%d ", item);
    }
    */

   while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!is_full(&myStack)) {
                    printf("Enter an item to push: ");
                    scanf("%d", &item);
                    push(&myStack, item);
                    printf("%d pushed onto the stack.\n", item);
                } else {
                    printf("Stack is full. Cannot push.\n");
                }
                break;
            case 2:
                if (!is_empty(&myStack)) {
                    item = pop(&myStack);
                    printf("%d popped from the stack.\n", item);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                if (!is_empty(&myStack)) {
                    printf("Stack elements:\n");
                    for (int i = 0; i <= myStack.top; i++) {
                        printf("%d\n", myStack.data[i]);
                    }
                    printf("\n");
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}