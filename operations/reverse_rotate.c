
#include "push_swap.h"

void rra(t_node **a, t_benchmark *bench)
{
	if (!a || !*a || !(*a)->next)
		return;
	t_node *last_node;
	t_node *current;

	current = *a;
	while (current->next->next)
	{
		current = current->next;
	}
	last_node = current->next;
	current->next = NULL;
	last_node->next = *a;
	*a = last_node;
	write(1, "rra\n", 4);
	benchmark_count(bench, OP_RRA);
}

void rrb(t_node **b, t_benchmark *bench)
{
	if (!b || !*b || !(*b)->next)
		return;
	t_node *last_node;
	t_node *current;

	current = *b;
	while (current->next->next)
	{
		current = current->next;
	}
	last_node = current->next;
	current->next = NULL;
	last_node->next = *b;
	*b = last_node;
	write(1, "rrb\n", 4);
	benchmark_count(bench, OP_RRB);
}

void rrr(t_node **a, t_node **b, t_benchmark *bench)
{
	rra(a, bench);
	rra(b, bench);
	benchmark_count(bench, OP_RRR);
}
