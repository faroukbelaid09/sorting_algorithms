#include "sort.h"

/**
 * swapNodes - Swap two nodes
 * @head: A pointer to the head of the doubly-linked list
 * @firstNode: A pointer to the first node
 * @secondNode: The second node
 */

void swapNodes(listint_t **head, listint_t **firstNode, listint_t *secondNode)
{
	(*firstNode)->next = secondNode->next;
	if (secondNode->next != NULL)
		secondNode->next->prev = *firstNode;
	secondNode->prev = (*firstNode)->prev;
	secondNode->next = *firstNode;
	if ((*firstNode)->prev != NULL)
		(*firstNode)->prev->next = secondNode;
	else
		*head = secondNode;
	(*firstNode)->prev = secondNode;
	*firstNode = secondNode->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers
 *
 * Description: Prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr;
	listint_t *insert;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		insert = itr->prev;
		while (insert != NULL && itr->n < insert->n)
		{
			swapNodes(list, &insert, itr);
			print_list((const listint_t *)*list);
		}
	}
}
