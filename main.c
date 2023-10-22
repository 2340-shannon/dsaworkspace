#include <stdio.h>
#include "stack.h"
#include "bracketmatching.h"
#include "BTree.h"
#include "infixpostfixevaluation.h"
#include "merge_sort.h"
#include "quicksort.h"
#include "shortest_path.h"
#define MAX 10
#define MAX_STACK_SIZE 100 


// Main program
int main() {
    int option;
    char infix[100];
    char postfix[100];
    char exp[100];
    int result;

    int size;
    Stack myStack;
    init(&myStack);
    int choice, item;

    int arr_size;
   
    int N; 
   
    node *root = NULL;
    int val;

    int Graph[MAX][MAX], i, j, n, u;
    n = 7;
    
    while (1)
    {
        printf("Enter:\n1)Stack \n2)Infixpostfix evaluation \n3)Bracket Matching \n4)Binary Tree \n5)Shortest distance \n6) Merge Sort \n7)Qiuck Sort");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                
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
                            push(&myStack,item);
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
            break;
            }

            case 2:
                
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                result = evaluatePostfix(postfix);

                printf("Postfix expression: %s\n", postfix);
                printf("Result: %d\n", result);

                break;
    

            case 3:
                 
                printf("Enter an expression: ");
                scanf("%s", exp);

                // Function call
                if (areBracketsBalanced(exp))
                    printf("Balanced\n");
                else
                    printf("Not Balanced\n");

                break;


            case 4:

                while (1) {
                    printf("1. Insert a value\n");
                    printf("2. Delete a value\n");
                    printf("3. Search for a value\n");
                    printf("4. Print Pre Order Display\n");
                    printf("5. Print In Order Display\n");
                    printf("6. Print Post Order Display\n");
                    printf("7. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter the value to insert: ");
                            scanf("%d", &val);
                            insert(&root, val);
                            break;
                        case 2:
                            printf("Enter the value to delete: ");
                            scanf("%d", &val);
                            root = deleteNode(root, val);
                            break;
                        case 3:
                            printf("Enter the value to search: ");
                            scanf("%d", &val);
                            node *result = search(root, val);
                            if (result) {
                                printf("node found =%d\n", result->data);
                            } else {
                                printf("Data not found in the tree.\n");
                            }
                            break;
                        case 4:
                            printf("Pre Order Display\n");
                            print_preorder(root);
                            break;
                        case 5:
                            printf("In Order Display\n");
                            print_inorder(root);
                            break;
                        case 6:
                            printf("Post Order Display\n");
                            print_postorder(root);
                            break;
                        case 7:
                            deltree(root);
                            return 0;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                break;

            case 5:

                Graph[0][0] = 0;
                Graph[0][1] = 0;
                Graph[0][2] = 1;
                Graph[0][3] = 2;
                Graph[0][4] = 0;
                Graph[0][5] = 0;
                Graph[0][6] = 0;

                Graph[1][0] = 0;
                Graph[1][1] = 0;
                Graph[1][2] = 2;
                Graph[1][3] = 0;
                Graph[1][4] = 0;
                Graph[1][5] = 3;
                Graph[1][6] = 0;

                Graph[2][0] = 1;
                Graph[2][1] = 2;
                Graph[2][2] = 0;
                Graph[2][3] = 1;
                Graph[2][4] = 3;
                Graph[2][5] = 0;
                Graph[2][6] = 0;

                Graph[3][0] = 2;
                Graph[3][1] = 0;
                Graph[3][2] = 1;
                Graph[3][3] = 0;
                Graph[3][4] = 0;
                Graph[3][5] = 0;
                Graph[3][6] = 1;

                Graph[4][0] = 0;
                Graph[4][1] = 0;
                Graph[4][2] = 3;
                Graph[4][3] = 0;
                Graph[4][4] = 0;
                Graph[4][5] = 2;
                Graph[4][6] = 0;

                Graph[5][0] = 0;
                Graph[5][1] = 3;
                Graph[5][2] = 0;
                Graph[5][3] = 0;
                Graph[5][4] = 2;
                Graph[5][5] = 0;
                Graph[5][6] = 1;

                Graph[6][0] = 0;
                Graph[6][1] = 0;
                Graph[6][2] = 0;
                Graph[6][3] = 1;
                Graph[6][4] = 0;
                Graph[6][5] = 1;
                Graph[6][6] = 0;

                u = 0;
                Dijkstra(Graph, n, u);

                break;


            case 6:
                
                printf("Enter the size of the array: ");
                scanf("%d", &arr_size);

                int *arr = (int*)malloc(arr_size * sizeof(int));
                
                if (arr == NULL) {
                    printf("Memory allocation failed. Exiting...\n");
                    exit(1);
                }

                printf("Enter the elements of the array, one by one:\n");
                for (int i = 0; i < arr_size; i++) {
                    printf("element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                    getchar(); // or use fflush(stdin);
                }

                printf("Initial array:\n");
                for (int i = 0; i < arr_size; i++)
                    printf("%d ", arr[i]);
                printf("\n");

                mergeSort(arr, 0, arr_size - 1);

                printf("\nSorted array:\n");
                for (int i = 0; i < arr_size; i++)
                    printf("%d ", arr[i]);
                printf("\n");

                free(arr); // Don't forget to free the allocated memory when you're done.

                break;


            case 7:
            {
            int numberOfElements;
            printf("Enter the number of elemets you want to sort:\n");
            scanf("%d", &numberOfElements);

            int arr1[numberOfElements];
            printf("Enter the elements:\n");
            for (int i = 0; i < numberOfElements; i++)
            {
                scanf("%d", &arr1[i]);
            }

            quickSort(arr, 0, numberOfElements - 1);
            printf("Sorted array: \n");
            for (int i = 0; i < numberOfElements; i++)
             printf("%d ", arr1[i]);
            break;
        }
            default:
            printf("Exiting the program");
            exit(0);
            }

        }

        

return 0;
}