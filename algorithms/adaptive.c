/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:39:32 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:39:38 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	look_disorder(t_node **a, t_node **b, t_benchmark *bench)
{
	if (bench->disorder < 0.2)
	{
		bench->effective_strategy = STRATEGY_SIMPLE;
		sort_simple(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		bench->effective_strategy = STRATEGY_MEDIUM;
		sort_medium(a, b, bench);
	}
	else
	{
		bench->effective_strategy = STRATEGY_COMPLEX;
		sort_complex(a, b, bench);
	}
}

void	sort_adaptive(t_node **a, t_node **b, t_benchmark *bench)
{
	int	size;

	size = get_stack_size(*a);
	if (size <= 5)
	{
		bench->effective_strategy = STRATEGY_SIMPLE;
		sort_simple(a, b, bench);
		return ;
	}
	look_disorder(a, b, bench);
}
