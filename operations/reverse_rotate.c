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

static int	reverse_rotate_stack(t_node **stack)
{
	t_node	*last_node;
	t_node	*current;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	current = *stack;
	while (current->next->next)
	{
		current = current->next;
	}
	last_node = current->next;
	current->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
	return (1);
}

void	rra(t_node **a, t_benchmark *bench)
{
	if (!reverse_rotate_stack(a))
		return ;
	write(1, "rra\n", 4);
	benchmark_count(bench, OP_RRA);
}

void	rrb(t_node **b, t_benchmark *bench)
{
	if (!reverse_rotate_stack(b))
		return ;
	write(1, "rrb\n", 4);
	benchmark_count(bench, OP_RRB);
}

void	rrr(t_node **a, t_node **b, t_benchmark *bench)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = reverse_rotate_stack(a);
	b_rotated = reverse_rotate_stack(b);
	if (!a_rotated && !b_rotated)
		return ;
	write(1, "rrr\n", 4);
	benchmark_count(bench, OP_RRR);
}
