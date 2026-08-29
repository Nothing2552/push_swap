/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:41:57 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 16:42:01 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_complexity(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		bench_putstr("Complexity: O(n^2)\n");
	else if (strategy == STRATEGY_MEDIUM)
		bench_putstr("Complexity: O(n*sqrt(n))\n");
	else if (strategy == STRATEGY_COMPLEX)
		bench_putstr("Complexity: O(n log n)\n");
}

static void	print_strategy_name(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		bench_putstr("simple\n");
	else if (strategy == STRATEGY_MEDIUM)
		bench_putstr("medium\n");
	else if (strategy == STRATEGY_COMPLEX)
		bench_putstr("complex\n");
}

static void	print_strategy(t_benchmark *bench)
{
	if (bench->strategy == STRATEGY_ADAPTIVE)
	{
		bench_putstr("Strategy: adaptive -> ");
		print_strategy_name(bench->effective_strategy);
		print_complexity(bench->effective_strategy);
	}
	else
	{
		bench_putstr("Strategy: ");
		print_strategy_name(bench->strategy);
		print_complexity(bench->strategy);
	}
}

static void	print_operation_counts(t_benchmark *bench)
{
	bench_put_metric("sa: ", bench->counts[OP_SA]);
	bench_put_metric("sb: ", bench->counts[OP_SB]);
	bench_put_metric("ss: ", bench->counts[OP_SS]);
	bench_put_metric("pa: ", bench->counts[OP_PA]);
	bench_put_metric("pb: ", bench->counts[OP_PB]);
	bench_put_metric("ra: ", bench->counts[OP_RA]);
	bench_put_metric("rb: ", bench->counts[OP_RB]);
	bench_put_metric("rr: ", bench->counts[OP_RR]);
	bench_put_metric("rra: ", bench->counts[OP_RRA]);
	bench_put_metric("rrb: ", bench->counts[OP_RRB]);
	bench_put_metric("rrr: ", bench->counts[OP_RRR]);
}

void	benchmark_print(t_benchmark *bench)
{
	if (!bench)
		return ;
	benchmark_print_disorder(bench->disorder);
	print_strategy(bench);
	bench_put_metric("Total operations: ", bench->total);
	print_operation_counts(bench);
}
