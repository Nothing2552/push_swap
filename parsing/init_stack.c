/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   init_stack.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:06:36 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 22:36:37 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Bu fonksiyon, verilen bir sayı için bellekte yeni bir stack elemanı oluşturur.

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	init_stack(t_node **a, int argc, char **argv, int start)
{
	t_node	*node;
	int		value;
	int		i;

	i = start;
	while (i < argc)
	{
		if (!parse_int(argv[i], &value))
			error_exit(a, NULL);
		if (has_duplicate(*a, value))
			error_exit(a, NULL);
		node = new_node(value);
		if (!node)
			error_exit(a, NULL);
		add_node_back(a, node);
		i++;
	}
}
