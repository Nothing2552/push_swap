#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int				value;
    struct s_node	*next;
}	t_node;

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

int		is_valid_input(int argc, char **argv);
void	free_stack(t_node **stack);
void	error_exit(t_node **a, t_node **b);

double	compute_disorder(t_node *a);
void	sort_simple(t_node **a, t_node **b);
void	sort_medium(t_node **a, t_node **b);
void	sort_complex(t_node **a, t_node **b);
void	sort_adaptive(t_node **a, t_node **b);

#endif