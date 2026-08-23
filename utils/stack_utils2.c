/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_utils2.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:35:03 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 22:35:29 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
