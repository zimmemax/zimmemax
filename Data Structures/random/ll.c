#include <stdlib.h>

#include "ll.h"

// struct node
// {
// 	int val;
// 	struct node *next;
// };


struct node* add_two_num (struct node* l1, struct node* l2)
{
	struct node* current = add_node(0);
	struct node* resultant = current;

	int sum = 0;
	

	while(l1 != NULL || l2 != NULL || sum)
	{
		if(l2){
			sum += l2->val;
		}
		else{
			sum += 0;
		}

		if(l1){
			sum += l1->val;
		}
		else{
			sum += 0;
		}

		current->next = add_node(sum%10);
		sum /= 10;
		current = current->next;

		if(l1)
		{
			l1 = l1->next;
		}
		if(l2)
		{
			l2 = l2->next;
		}


	} 

	return resultant->next;;
}

struct node* add_node(int value)
{
	struct node* head = malloc(sizeof(struct node));
	head->val = value;
	head->next = NULL;
	return head;
	
}


