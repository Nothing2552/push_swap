
#include "push_swap.h"

void merge_sort(int *values, 0, size - 1)
{
}

int assign_indexes(t_node *stack)
{
	int *values;
	int size;

	size = stack_size(stack);
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