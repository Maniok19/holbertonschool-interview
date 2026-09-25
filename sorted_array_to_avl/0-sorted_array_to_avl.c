#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - Recursively builds the AVL tree from sorted array
 * @array: Pointer to the array
 * @start: Starting index
 * @end: Ending index
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the subtree, or NULL on failure
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(array, start, mid - 1, root);
	root->right = build_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
