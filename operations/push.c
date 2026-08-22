/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:08:32 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/22 20:08:16 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (is_empty(b))
		return ;
	temp = pop(b);
	push(a, temp);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (is_empty(a))
		return ;
	temp = pop(a);
	push(b, temp);
}