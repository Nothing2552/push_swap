
#include "push_swap.h"

int is_empty(t_node **a)
{
    if (!a || !(*a))
        return (1);
    return (0);
}
t_node *pop(t_node **a)
{
    t_node *node_to_pop;

    if (is_empty(a))
        return (NULL);
    node_to_pop = *a;
    *a = (*a)->next;
    node_to_pop->next = NULL;
    return (node_to_pop);
}

void push(t_node **a, t_node *node_to_push)
{
    if (!node_to_push)
        return ;
    node_to_push->next = *a;
    *a = node_to_push;
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
