#include "binary_trees.h"

int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level);
size_t get_depth(const binary_tree_t *tree);

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect, 0 if tree is NULL or not perfect
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t depth;

if (tree == NULL)
return (0);

depth = get_depth(tree);
return (is_perfect_recursive(tree, depth, 0));
}

/**
* get_depth - Finds the depth of the leftmost leaf node
* @tree: Pointer to the root node
*
* Return: Depth of the leftmost branch
*/
size_t get_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree != NULL)
{
depth++;
tree = tree->left;
}
return (depth);
}

/**
* is_perfect_recursive - Recursively checks if all subtrees are perfect
* @tree: Pointer to current node
* @depth: Expected depth of all leaf nodes
* @level: Current depth level of the node
*
* Return: 1 if perfect, 0 otherwise
*/
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
if (tree->left == NULL && tree->right == NULL)
return (depth == level + 1);

if (tree->left == NULL || tree->right == NULL)
return (0);

return (is_perfect_recursive(tree->left, depth, level + 1) &&
is_perfect_recursive(tree->right, depth, level + 1));
}
