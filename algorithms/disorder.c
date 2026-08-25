
#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	t_node	*first;
	t_node	*second;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	first = stack;
	while (first)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}