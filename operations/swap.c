/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:17:42 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 14:27:16 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **a, t_benchmark *bench)
{
	t_node *first;
	t_node *second;

	if (is_empty(a) || !(*a)->next)
		return;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
	benchmark_count(bench, OP_SA);
}

void sb(t_node **b, t_benchmark *bench)
{
	t_node *first;
	t_node *second;

	if (is_empty(b) || !(*b)->next)
		return;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
	benchmark_count(bench, OP_SB);
}

void ss(t_node **a, t_node **b, t_benchmark *bench)
{
	sa(a, bench);
	sa(b, bench);
	benchmark_count(bench, OP_SS);
}
