/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:08:32 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 14:14:54 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_node **a, t_node **b, t_benchmark *bench)
{
	t_node *temp;

	if (is_empty(b))
		return;
	temp = pop(b);
	push(a, temp);
	write(1, "pa\n", 3);
	benchmark_count(bench, OP_PA);
}

void pb(t_node **a, t_node **b, t_benchmark *bench)
{
	t_node *temp;

	if (is_empty(a))
		return;
	temp = pop(a);
	push(b, temp);
	write(1, "pb\n", 3);
	benchmark_count(bench, OP_PB);
}