#include "binary_trees.h"

bst_t *inorder_next(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_rm_rec(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_next - Returns the minimum value of a binary search tree.
 *
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_next(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 *
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *next = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;

		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;

		free(node);
		return (parent == NULL ? node->left : root);
	}

	next = inorder_next(node->right);
	node->n = next->n;

	return (bst_delete(root, next));
}

/**
 * bst_rm_rec - Removes a node from a binary search tree recursively.
 *
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_rm_rec(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_rm_rec(root, node->left, value));

		return (bst_rm_rec(root, node->right, value));
	}

	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 *
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_rm_rec(root, root, value));
}
