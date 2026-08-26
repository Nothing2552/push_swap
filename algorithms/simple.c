/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/24 13:34:34 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:11:13 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_b(t_node **a, t_node **b,
	int min_idx, t_benchmark *bench)
{
	int	size;

	size = get_stack_size(*a);
	if (min_idx <= size / 2)
	{
		while (min_idx-- > 0)
			ra(a, bench);
	}
	else
	{
		while (min_idx++ < size)
			rra(a, bench);
	}
	pb(a, b, bench);
}

static void	sort_three(t_node **a, t_benchmark *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		ra(a, bench);
	else if (second > first && second > third)
		rra(a, bench);
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

static void	sort_small(t_node **a, t_node **b, t_benchmark *bench)
{
	int	min_idx;
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
	{
		sa(a, bench);
		return ;
	}
	while (get_stack_size(*a) > 3)
	{
		min_idx = find_min_index(a);
		move_min_to_b(a, b, min_idx, bench);
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}

void	sort_simple(t_node **a, t_node **b, t_benchmark *bench)
{
	int	size;
	int	min_idx;

	if (!a || is_sorted(*a))
		return ;
	size = get_stack_size(*a);
	if (size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	while (get_stack_size(*a) > 3)
	{
		min_idx = find_min_index(a);
		move_min_to_b(a, b, min_idx, bench);
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
