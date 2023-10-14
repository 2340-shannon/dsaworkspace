#ifndef BINARYTREE_H
#define BINARYTREE_H

struct bin_tree {
    int data;
    struct bin_tree *left, *right;
};
typedef struct bin_tree node;

void insert(node **tree, int val);
node *search(node *tree, int val);
node *deleteNode(node *tree, int val);
void print_preorder(node *tree);
void print_inorder(node *tree);
void print_postorder(node *tree);
void deltree(node *tree);

#endif
