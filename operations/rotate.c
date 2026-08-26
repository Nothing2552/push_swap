/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 20:46:20 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:13:02 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*last_node;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	last_node = find_last_node(a);
	last_node->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
	benchmark_count(bench, OP_RA);
}

void	rb(t_node **b, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*last_node;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	last_node = find_last_node(b);
	last_node->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
	benchmark_count(bench, OP_RB);
}

void	rr(t_node **a, t_node **b, t_benchmark *bench)
{
	ra(a, bench);
	ra(b, bench);
	benchmark_count(bench, OP_RR);
}
