
#include "push_swap.h"

int	is_empty(t_node	**a)
{
	if (!a || !(*a))
		return (0);
	return (1);
}
t_node	*pop(t_node **a)
{
	t_node	*new_node;

	new_node = *a;
	*a = (*a)->next;
	return (new_node);
}

void	push(t_node **a, t_node *b)
{
	b->next = *a;
	*a = b;
}
t_node	*find_last_node(t_node	**a)
{
	t_node	*current;

	current = *a;
	while(current->next)
	{
		current = current->next;
	}
	return (current);
}
