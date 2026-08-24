/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:34:34 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 14:37:23 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	get_stack_size(t_node *a)
{
    int size;

    size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}

static int	find_min_index(t_node **a)
{
    t_node  *curr;
    int     min_val;
    int     i;
    int     min_idx;

    if (!a || !*a)
        return (-1);
    curr = *a;
    min_val = __INT_MAX__;
    i = 0;
    min_idx = 0;
    while (curr)
    {
        if (curr->value < min_val)
        {
            min_val = curr->value;
            min_idx = i;
        }
        curr = curr->next;
        i++;
    }
    return (min_idx);
}
static int	util_operations(t_node **a, t_node **b, int size, int min_idx)
{
	int count_operations;

	count_operations = 0;
    if (min_idx <= size / 2)
    {
        while (min_idx > 0)
        {
            ra(a);
			count_operations++;
            min_idx--;
        }
    }
    else
    {
        while (min_idx < size)
        {
            rra(a);
			count_operations++;
            min_idx++;
        }
    }
    pb(a, b);
	count_operations++;
	return (count_operations);
}

int	sort_simple(t_node **a, t_node **b)
{
    int size;
    int min_idx;
	int	count_operations;

	count_operations = 0;
	if (!a || is_sorted(*a))
		return (0);
    while (!is_empty(a))
    {
        size = get_stack_size(*a);
        min_idx = find_min_index(a);
		count_operations += util_operations(a, b, size, min_idx);
    }
    while (!is_empty(b))
    {
        pa(a, b);
		count_operations++;
    }
	return (count_operations);
}
