#include "binary_trees.h"
/**
 * tree_size - prints
 * @tree: tree
 *
 * Return: Always 0 (Success)
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}
/**
 * node_at_index - prints
 * @root: tree
 * @index: index
 *
 * Return: Always 0 (Success)
 */
static heap_t *node_at_index(heap_t *root, size_t index)
{
	size_t bit;

	if (!root || index == 0)
		return (NULL);

	for (bit = 1; bit <= index; bit <<= 1)
		;
	bit >>= 2;

	while (bit && root)
	{
		if (index & bit)
			root = root->right;
		else
			root = root->left;
		bit >>= 1;
	}

	return (root);
}
/**
 * sift_up - prints
 * @node: tree
 *
 * Return: Always 0 (Success)
 */
static heap_t *sift_up(heap_t *node)
{
	int tmp;

	while (node && node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}
/**
 * heap_insert - prints
 * @root: tree
 * @value: val
 *
 * Return: Always 0 (Success)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;
	size_t new_index;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		if (!*root)
			return (NULL);
		(*root)->left = NULL;
		(*root)->right = NULL;
		return (*root);
	}

	new_index = tree_size(*root) + 1;
	parent = node_at_index(*root, new_index / 2);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;

	if (new_index % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (sift_up(new_node));
}
