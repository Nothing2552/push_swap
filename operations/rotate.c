/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:46:20 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 14:26:30 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_node **a, t_benchmark *bench)
{
	if (!a || !*a || !(*a)->next)
		return;
	t_node *temp;
	t_node *last_node;

	temp = *a;
	*a = (*a)->next;
	last_node = find_last_node(a);
	last_node->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
	benchmark_count(bench, OP_RA);
}

void rb(t_node **b, t_benchmark *bench)
{
	if (!b || !*b || !(*b)->next)
		return;
	t_node *temp;
	t_node *last_node;

	temp = *b;
	*b = (*b)->next;
	last_node = find_last_node(b);
	last_node->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
	benchmark_count(bench, OP_RB);
}
void rr(t_node **a, t_node **b, t_benchmark *bench)
{
	ra(a, bench);
	ra(b, bench);
	benchmark_count(bench, OP_RR);
}
