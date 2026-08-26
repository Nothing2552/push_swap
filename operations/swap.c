/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 20:17:42 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:10:26 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (is_empty(stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_node **a, t_benchmark *bench)
{
	if (!swap_stack(a))
		return ;
	write(1, "sa\n", 3);
	benchmark_count(bench, OP_SA);
}

void	sb(t_node **b, t_benchmark *bench)
{
	if (!swap_stack(b))
		return ;
	write(1, "sb\n", 3);
	benchmark_count(bench, OP_SB);
}

void	ss(t_node **a, t_node **b, t_benchmark *bench)
{
	int	a_swapped;
	int	b_swapped;

	a_swapped = swap_stack(a);
	b_swapped = swap_stack(b);
	if (!a_swapped && !b_swapped)
		return ;
	write(1, "ss\n", 3);
	benchmark_count(bench, OP_SS);
}
