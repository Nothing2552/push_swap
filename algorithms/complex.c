/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:49:24 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:39:58 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *stack)
{
	t_node	*current;
	int		max_index;
	int		max_bits;

	max_index = 0;
	max_bits = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	restore_to_a(t_node **a, t_node **b, t_benchmark *bench)
{
	int	moves;

	moves = 0;
	while (*b)
	{
		pa(a, b, bench);
		moves++;
	}
	return (moves);
}

static int	radix_process_bit(t_node **a, t_node **b,
	int bit, t_benchmark *bench)
{
	int	j;
	int	size;

	size = get_stack_size(*a);
	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, bench);
		else
			pb(a, b, bench);
		j++;
	}
	return (size + restore_to_a(a, b, bench));
}

int	radix_sort(t_node **stack_a, t_node **stack_b, t_benchmark *bench)
{
	int	i;
	int	max_bits;
	int	size;
	int	total_moves;

	i = 0;
	total_moves = 0;
	size = get_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		if (is_sorted(*stack_a))
			break ;
		total_moves += radix_process_bit(stack_a, stack_b, i, bench);
		i++;
	}
	return (total_moves);
}

void	sort_complex(t_node **a, t_node **b, t_benchmark *bench)
{
	if (!a || !*a || !(*a)->next || is_sorted(*a))
		return ;
	if (!assign_indexes(*a))
		error_exit(a, b);
	radix_sort(a, b, bench);
}
