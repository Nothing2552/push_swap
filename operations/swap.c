/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 20:17:42 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 21:24:19 by aryaprak        ###   ########.fr        */
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
	t_node	*first;
	t_node	*second;

	if (is_empty(b) || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
