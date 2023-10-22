#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"


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
node *find_min(node *tree) {
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

//void node*deletenode
node *deleteNode(node *tree, int val) {
    if (tree == NULL) {
        return tree;
    }

    if (val < tree->data) {
        tree->left = deleteNode(tree->left, val);
    } else if (val > tree->data) {
        tree->right = deleteNode(tree->right, val);
    } else {
        if (tree->left == NULL) {
            node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            node *temp = tree->left;
            free(tree);
            return temp;
        }

        node *temp = find_min(tree->right);
        tree->data = temp->data;
        tree->right = deleteNode(tree->right, temp->data);
    }
    return tree;
}

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


