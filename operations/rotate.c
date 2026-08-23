/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:46:20 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/22 21:00:32 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	if (!a || !*a || !(*a)->next)
    	return ;
	t_node	*temp;
	t_node	*last_node;

	temp = *a;
	*a = (*a)->next;
	last_node = find_last_node(a);
	last_node->next = temp;
	temp->next = NULL;
}

void	rb(t_node **b)
{
	ra(b);
}
void	rr(t_node **a, t_node **b)
{
	ra(a);
	ra(b);
}
