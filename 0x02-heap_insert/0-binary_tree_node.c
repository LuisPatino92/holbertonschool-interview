#include "binary_trees.h"

/**
 * binary_tree_node - heap insert of a node
 * @parent: node
 * @value: value for new node
 *
 * Return: NULL || new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n = NULL;

	n = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	n->parent = parent;
	n->left = NULL;
	n->right = NULL;
	n->n = value;

	return (new_node);
}