/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:34:34 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/26 16:27:38 by yaydilek         ###   ########.fr       */
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

static int	util_operations(t_node **a, t_node **b, int size, int min_idx, t_benchmark *bench)
{
	int count_operations;

	count_operations = 0;
    if (min_idx <= size / 2)
    {
        while (min_idx > 0)
        {
            ra(a, bench);
			count_operations++;
            min_idx--;
        }
    }
    else
    {
        while (min_idx < size)
        {
            rra(a, bench);
			count_operations++;
            min_idx++;
        }
    }
    pb(a, b, bench);
	count_operations++;
	return (count_operations);
}

int sort_three(t_node **a, t_benchmark *bench)
{
    int count_operations;
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;

    count_operations = 0;
    if (first > second && first > third)
    {
        ra(a, bench);
        count_operations++;
    }
    else if (second > first && second > third)
    {
        rra(a, bench);
        count_operations++;
    }
    if ((*a)->value > (*a)->next->value)
    {
        sa(a, bench);
        count_operations++;
    }
    return (count_operations);
}
int simple_conditions(t_node **a, t_node **b, int size, int min_idx, t_benchmark *bench)
{
    int count_operations;

    count_operations = 0;
    if (size == 2)
    {
        sa(a, bench);
        return (1);
    }
    while (get_stack_size(*a) > 3)
    {
        min_idx = find_min_index(a);
        count_operations += util_operations(a, b, get_stack_size(*a), min_idx, bench);
    }
    count_operations += sort_three(a, bench);
    pa(a, b, bench);
    pa(a, b, bench);
    
    return (count_operations);
}

int	sort_simple(t_node **a, t_node **b, t_benchmark *bench)
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
        if (size <= 5)
        {
            return (simple_conditions(a, b, size, min_idx, bench));
        }
		count_operations += util_operations(a, b, size, min_idx, bench);
    }
    while (!is_empty(b))
    {
        pa(a, b, bench);
		count_operations++;
    }
	return (count_operations);
}

