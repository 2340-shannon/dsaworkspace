#include <stdio.h>
#include <stdlib.h>
#define bool int


struct sNode {
	char data;
	struct sNode* next;
};

void push(struct sNode** top_ref, int new_data);

int pop(struct sNode** top_ref);

bool isMatchingPair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

// Return 1 if expression has balanced Brackets
//areBracketsBalanced

int main()
{
    char exp[100];

    printf("Enter an expression: ");
    scanf("%s", exp);

    
    //if statement


}


// Function to push an item to stack
void push(struct sNode** top_ref, int new_data)
{
	
	struct sNode* new_node
		= (struct sNode*)malloc(sizeof(struct sNode));

	if (new_node == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	// put in the data
	new_node->data = new_data;

	// link the old list of the new node
	new_node->next = (*top_ref);

	// move the head to point to the new node
	(*top_ref) = new_node;
}


// Function to pop an item from stack
