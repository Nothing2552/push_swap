/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:11:12 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:41:18 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int size)
{
	int	i;

	i = 1;
	if (size <= 0)
		return (0);
	while (i * i < size)
		i++;
	return (i);
}

static int	is_sorted_medium(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_chunks(t_node **a, t_node **b, int range, t_benchmark *bench)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, bench);
			rb(b, bench);
			pushed++;
		}
		else if ((*a)->index <= pushed + range)
		{
			pb(a, b, bench);
			pushed++;
		}
		else
			ra(a, bench);
	}
}

static int	find_max_position(t_node *stack)
{
	int	max_index;
	int	max_position;
	int	position;

	max_index = stack->index;
	max_position = 0;
	position = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_position = position;
		}
		stack = stack->next;
		position++;
	}
	return (max_position);
}

void	sort_medium(t_node **a, t_node **b, t_benchmark *bench)
{
	int	size;
	int	range;
	int	max_position;

	if (!a || !*a || !(*a)->next)
		return ;
	if (!assign_indexes(*a))
		error_exit(a, b);
	if (is_sorted_medium(*a))
		return ;
	size = get_stack_size(*a);
	range = int_sqrt(size);
	push_chunks(a, b, range, bench);
	while (*b)
	{
		max_position = find_max_position(*b);
		size = get_stack_size(*b);
		if (max_position <= size / 2)
			while (max_position-- > 0)
				rb(b, bench);
		else
			while (max_position++ < size)
				rrb(b, bench);
		pa(a, b, bench);
	}
}
