/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   error.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:35:53 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 22:35:59 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node **a, t_node **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
