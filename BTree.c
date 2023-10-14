#include <stdlib.h>
#include <stdio.h>

struct bin_tree {
    int data;
    struct bin_tree *left, *right;
};
typedef struct bin_tree node;

void insert(node **tree, int val) {
    node *temp = NULL;
    if (!(*tree)) {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if (val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if (val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }
}


//node *find_min


//void node*deletenode


void print_preorder(node *tree) {
    if (tree) {
        printf("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node *tree) {
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n", tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node *tree) {
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n", tree->data);
    }
}

void deltree(node *tree) {
    if (tree) {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node *search(node *tree, int val) {
    if (tree == NULL) {
        return NULL;
    }

    if (val < tree->data) {
        return search(tree->left, val);
    } else if (val > tree->data) {
        return search(tree->right, val);
    } else if (val == tree->data) {
        return tree;
    }
}

int main() {
    node *root = NULL;
    int choice;
    int val;

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
}
