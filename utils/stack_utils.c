/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 21:24:15 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 21:24:15 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_node **a)
{
	if (!a || !(*a))
		return (1);
	return (0);
}

t_node	*pop(t_node **a)
{
	t_node	*new_node;

	new_node = *a;
	*a = (*a)->next;
	return (new_node);
}

void	push(t_node **a, t_node *b)
{
	b->next = *a;
	*a = b;
}
