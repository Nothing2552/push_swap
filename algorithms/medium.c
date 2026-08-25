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

static int is_sorted_medium(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
static void	push_chunks(t_node **a, t_node **b, int range)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if ((*a)->index <= pushed + range)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
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
void	sort_medium(t_node **a, t_node **b)
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
	push_chunks(a, b, range);
	while (*b)
	{
		max_position = find_max_position(*b);
		size = get_stack_size(*b);
		if (max_position <= size / 2)
			while (max_position-- > 0)
				rb(b);
		else
			while (max_position++ < size)
				rrb(b);
		pa(a, b);
	}
}