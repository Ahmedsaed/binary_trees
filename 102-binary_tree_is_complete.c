#include "binary_trees.h"

/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_last_level = 0;
	int is_complete = 1;
	binary_tree_t *queue[1000];
	int front = -1, rear = -1;

	if (tree == NULL)
		return (0);

	queue[++rear] = (binary_tree_t *)tree;

	while (front != rear)
	{
		binary_tree_t *current = queue[++front];

		if (current->left != NULL)
		{
			if (is_last_level)
			{
				is_complete = 0;
				break;
			}
			queue[++rear] = current->left;
		}
		else
			is_last_level = 1;

		if (current->right != NULL)
		{
			if (is_last_level)
			{
				is_complete = 0;
				break;
			}
			queue[++rear] = current->right;
		}
		else
			is_last_level = 1;
	}

	return (is_complete);
}
