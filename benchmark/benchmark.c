/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:42:50 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:42:54 by aryaprak         ###   ########.fr       */
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
	bench->effective_strategy = STRATEGY_ADAPTIVE;
}

void	benchmark_count(t_benchmark *bench, t_operation operation)
{
	if (!bench || operation < OP_SA || operation >= OP_COUNT)
		return ;
	bench->counts[operation]++;
	bench->total++;
}
