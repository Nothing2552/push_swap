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
	t_node	*first;
	t_node	*second;

	if (is_empty(a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_node **b)
{
	sa(b);
}
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sa(b);
}
