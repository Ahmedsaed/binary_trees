#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree, int lower, int higher);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;

		return ((l > r) ? l : r);
	}

	return (0);
}

/**
 * is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @lower: The value of the smallest node visited thus far.
 * @higher: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl(const binary_tree_t *tree, int lower, int higher)
{
	size_t left_height, right_height, diff;

	if (tree != NULL)
	{
		if (tree->n < lower || tree->n > higher)
			return (0);

		left_height = height(tree->left);
		right_height = height(tree->right);
		diff = left_height > right_height ?
				left_height - right_height :
				right_height - left_height;

		if (diff > 1)
			return (0);

		return (is_avl(tree->left, lower, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, higher));
	}

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
