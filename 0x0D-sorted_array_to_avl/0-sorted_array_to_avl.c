#include "binary_trees.h"

/**
 * binary_tree_node - creates a node
 * @parent: pointer to parent
 * @value: value for node
 *
 * Return: Null or new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;
	new = malloc(sizeof(binary_tree_t));

	if (new) {
		new->parent = parent;
		new->left = NULL;
		new->right = NULL;
		new->n = value;

		return (new);
	} else {
		return (NULL);
	}
}
/**
 * sort_insert - Aux function
 * @array: pointer to the array
 * @min: lower lim
 * @max: upper lim
 *
 * Return: Null or Root node
 */
avl_t *sort_insert(int *array, int min, int max)
{
	int half;
	avl_t *tree;

	if (min > max)
		return (NULL);

	half = (max + min) / 2;

	tree = binary_tree_node(NULL, array[half]);
	if (!tree)
		return (NULL);

	tree->left = sort_insert(array, min, half - 1);

	tree->right = sort_insert(array, half + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);

	root = sort_insert(array, 0, size - 1);

	return (root);
}
