/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:17:42 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/22 20:32:58 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*temp1;
	t_node	*temp2;

	if (is_empty(a) || (*a)->next)
		return ;
	temp1 = (*a);
	temp1->next = (*a)->next->next;
	(*a)->next = temp1;
}

void	sb(t_node **b)
{
	t_node	*temp1;
	t_node	*temp2;

	if (is_empty(b) || (*b)->next)
		return ;
	temp1 = (*b);
	temp1->next = (*b)->next->next;
	(*b)->next = temp1;
}
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
