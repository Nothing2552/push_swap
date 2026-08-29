/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:06:36 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:45:51 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int value)
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

static void	add_node_back(t_node **stack, t_node *new)
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

int	init_stack(t_node **a, int argc, char **argv, int start)
{
	t_node	*node;
	int		value;
	int		i;

	i = start;
	while (i < argc)
	{
		if (!parse_int(argv[i], &value))
			return (0);
		if (has_duplicate(*a, value))
			return (0);
		node = new_node(value);
		if (!node)
			return (0);
		add_node_back(a, node);
		i++;
	}
	return (1);
}
