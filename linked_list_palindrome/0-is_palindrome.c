#include "lists.h"
#include <stddef.h>
/**
 * is_palindrome - check the code for Holberton School students.
 *
 * @head: linked list
 * Return: Always 0. or sometime 1
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *prev = NULL;
	listint_t *curr;
	listint_t *next_temp;
	listint_t *first_half;
	listint_t *second_half;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	curr = slow;
	prev = NULL;
	while (curr != NULL)
	{
		next_temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next_temp;
	}
	first_half = *head;
	second_half = prev;

	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			return (0);
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}
	return (1);
}

