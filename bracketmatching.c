#include <stdio.h>
#include <stdlib.h>
#include"bracketmatching.h"
#define bool int

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
bool areBracketsBalanced(char exp[])
{
	int i = 0;

	// Declare an empty character stack
	struct sNode* stack = NULL;

	// Traverse the given expression to check matching
	// brackets
	while (exp[i]) 
	{
		// If the exp[i] is a starting bracket then push
		// it
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			pushin(&stack, exp[i]);

		// If exp[i] is an ending bracket then pop from
		// stack and check if the popped bracket is a
		// matching pair*/
		if (exp[i] == '}' || exp[i] == ')'
			|| exp[i] == ']') {

			// If we see an ending bracket without a pair
			// then return false
			if (stack == NULL)
				return 0;

			// Pop the top element from stack, if it is not
			// a pair bracket of character then there is a
			// mismatch.
			// his happens for expressions like {(})
			else if (!isMatchingPair(popout(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	// If there is something left in expression then there
	// is a starting bracket without a closing
	// bracket
	if (stack == NULL)
		return 1; // balanced
	else
		return 0; // not balanced
}


// Function to push an item to stack
void pushin(struct sNode** top_ref, int new_data)
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
int popout(struct sNode** top_ref)
{
	char res;
	struct sNode* top;

	// If stack is empty then error
	if (*top_ref == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
