#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_h = 0;
size_t right_h = 0;

if (tree == NULL)
return (0);

left_h = binary_tree_height(tree->left);
right_h = binary_tree_height(tree->right);

if (left_h > right_h)
return (1 + left_h);

return (1 + right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure balance factor
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left_h = 0;
int right_h = 0;

if (tree == NULL)
return (0);

left_h = (int)binary_tree_height(tree->left);
right_h = (int)binary_tree_height(tree->right);

return (left_h - right_h);
}
