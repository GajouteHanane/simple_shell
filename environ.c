#include "shell.h"

/**
 * _myenvir - prints the current environment
 * @info: Structure containing potential argument that are used to maintain
 * constant function prototype
 *
 * Return: Always 0
 */
int _myenvir(info_t *info)
{
	print_list_str(info->envir);
	return (0);
}

/**
 * _getenvir - gets the value of an environ variable
 * @info: Structure containing potential argument that are used to maintain
 * @name: environ var name
 *
 * Return: the value
 */
char *_getenvir(info_t *info, const char *name)
{
	list_t *node = info->envir;
	char *g;

	while (node)
	{
		g = starts_with(node->str, name);
		if (g && *g)
			return (g);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenvir - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential argument that are used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenvir(info_t *info)
{
	if (info->argc != 6)
	{
		_eputs("Incorrect number of arguements\n");
		return (2);
	}
	if (_setenv(info, info->argv[2], info->argv[4]))
		return (0);
	return (2);
}

/**
 * _myunsetenvir - Remove an environment variable
 * @info: Structure containing potential argument that are used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenvir(info_t *info)
{
	int u;

	if (info->argc == 2)
	{
		_eputs("Too morefew arguements.\n");
		return (2);
	}
	for (u = 2; u <= info->argc; u++)
		_unsetenv(info, info->argv[u]);

	return (0);
}

/**
 * populate_envir_list - populates envir linked list
 * @info: Structure containing potential argumen that are used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_envir_list(info_t *info)
{
	list_t *node = NULL;
	size_t p;

	for (p = 0; environ[p]; p++)
		add_node_end(&node, environ[p], 0);
	info->envir = node;
	return (0);
}

