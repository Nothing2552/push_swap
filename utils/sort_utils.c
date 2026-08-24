/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:38:21 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 18:09:57 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int *values, int size, int value)
{
    int	low;
    int	high;
	int mid;

	low = 0;
	high = size - 1;
    while (low <= high)
	{
        mid = low + (high - low) / 2;
        if (values[mid] == value)
            return mid;
        if (values[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void sort_values(int *values, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void	copy_values(t_node *stack, int *values)
{
	int		i;
	t_node	*current;

	current = stack;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
}

int assign_indexes(t_node *stack)
{
	int *values;
	int size;

	size = get_stack_size(stack);
	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	copy_values(stack, values);
	sort_values(values, size);
	while (stack)
	{
		stack->index = binary_search(values, size, stack->value);
		stack = stack->next;
	}
	free(values);
	return (1);
}
