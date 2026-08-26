/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   benchmark.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/26 20:10:59 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:10:59 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	benchmark_init(t_benchmark *bench)
{
	int	i;

	if (!bench)
		return ;
	i = 0;
	while (i < OP_COUNT)
	{
		bench->counts[i] = 0;
		i++;
	}
	bench->total = 0;
	bench->disorder = 0.0;
	bench->strategy = STRATEGY_ADAPTIVE;
}

void	benchmark_count(t_benchmark *bench, t_operation operation)
{
	if (!bench || operation < OP_SA || operation >= OP_COUNT)
		return ;
	bench->counts[operation]++;
	bench->total++;
}
