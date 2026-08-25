
#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
    int max_index = 0;
    int max_bits = 0;
    t_node *current = stack;

    while (current != NULL) 
    {
        if (current->index > max_index)
            max_index = current->index;
        current = current->next;
    }

    while ((max_index >> max_bits) != 0)
        max_bits++;
        
    return (max_bits);
}

int radix_process_bit(t_node **stack_a, t_node **stack_b, int bit, int size)
{
    int j;
    int moves;

    j = 0;
    moves = 0;
    while (j < size)
    {
        if ((((*stack_a)->index >> bit) & 1))
        {
            ra(stack_a);
            moves++;
        }
        else
        {
            pb(stack_a, stack_b);
            moves++;
        }
        j++;
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b);
        moves++;
    }
    return (moves);
}

int radix_sort(t_node **stack_a, t_node **stack_b)
{
    int i;
    int max_bits;
    int size;
    int total_moves;

    i = 0;
    total_moves = 0;
    size = get_stack_size(*stack_a);
    max_bits = get_max_bits(*stack_a);
    
    while (i < max_bits)
    {
		if (is_sorted(*stack_a))
            break;
        total_moves += radix_process_bit(stack_a, stack_b, i, size);
        i++;
    }
    return (total_moves);
}
