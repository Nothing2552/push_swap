#include "push_swap.h"
static int int_sqrt(int size)
{
	int i;

	i = 1;
	if (size <= 0)
		return (0);
	while (i * i < size)
		i++;
	return (i);
}
static int stack_size(t_node *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
static void push_chunks()