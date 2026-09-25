#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 *         or NULL if value is not present or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;

	if (!list)
		return (NULL);

	/* Start from the express lane */
	express = list->express;
	prev = list;

	/* Traverse the express lane */
	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   express->index, express->n);

		if (express->n >= value)
			break;

		prev = express;
		express = express->express;
	}

	/* Determine the range for linear search */
	if (express)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
	}
	else
	{
		/* Find the last node */
		express = prev;
		while (express->next)
			express = express->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
	}

	/* Linear search in the identified range */
	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		if (prev->n > value)
			break;

		prev = prev->next;
	}

	return (NULL);
}
