/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse_rotate.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/26 20:10:22 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:12:40 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, t_benchmark *bench)
{
	t_node	*last_node;
	t_node	*current;

	if (!a || !*a || !(*a)->next)
		return ;
	current = *a;
	while (current->next->next)
	{
		current = current->next;
	}
	last_node = current->next;
	current->next = NULL;
	last_node->next = *a;
	*a = last_node;
	write(1, "rra\n", 4);
	benchmark_count(bench, OP_RRA);
}

void	rrb(t_node **b, t_benchmark *bench)
{
	t_node	*last_node;
	t_node	*current;

	if (!b || !*b || !(*b)->next)
		return ;
	current = *b;
	while (current->next->next)
	{
		current = current->next;
	}
	last_node = current->next;
	current->next = NULL;
	last_node->next = *b;
	*b = last_node;
	write(1, "rrb\n", 4);
	benchmark_count(bench, OP_RRB);
}

void	rrr(t_node **a, t_node **b, t_benchmark *bench)
{
	rra(a, bench);
	rra(b, bench);
	benchmark_count(bench, OP_RRR);
}
