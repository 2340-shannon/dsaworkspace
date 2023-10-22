#ifndef BRACKET_CHECKER_H
#define BRACKET_CHECKER_H

#include <stdio.h>
#include <stdlib.h>

#define bool int

struct sNode {
    char data;
    struct sNode* next;
};

// Function to push an item to the stack
void pushin(struct sNode** top_ref, int new_data);

// Function to pop an item from the stack
int popout(struct sNode** top_ref);

// Returns 1 if character1 and character2 are matching left and right brackets
bool isMatchingPair(char character1, char character2);

// Return 1 if expression has balanced brackets
bool areBracketsBalanced(char exp[]);

#endif
