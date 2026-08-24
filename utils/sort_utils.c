/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:38:21 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/24 16:54:12 by yaydilek         ###   ########.fr       */
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

void	merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k] = L[i];
            i++;
        }
        else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
	{
        int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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
	merge_sort(values, 0, size - 1);
	while (stack)
	{
		stack->index = binary_search(values, size, stack->value);
		stack = stack->next;
	}
	free(values);
	return (1);
}
