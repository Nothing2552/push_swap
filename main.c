/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:38:28 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 22:38:28 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void prepare_benchmark(t_benchmark *bench, t_node *a,
							  t_options *options)
{
	benchmark_init(bench);
	bench->disorder = compute_disorder(a);
	bench->strategy = options->strategy;
}

static void run_strategy(t_node **a, t_node **b, t_options *options, t_benchmark *bench)
{
	if (options->strategy == STRATEGY_SIMPLE)
		sort_simple(a, b, bench);
	else if (options->strategy == STRATEGY_MEDIUM)
	{
		assign_indexes(*a);
		sort_medium(a, b, bench);
	}
	else if (options->strategy == STRATEGY_COMPLEX)
	{
		assign_indexes(*a);
		radix_sort(a, b, bench);
	}
	else
	{
		if (get_stack_size(*a) <= 5)
			sort_simple(a, b, bench);
		else
		{
			assign_indexes(*a);
			radix_sort(a, b, bench);
		}
	}
}

int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;
	t_options options;
	t_benchmark bench;
	int start;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	start = parse_options(argc, argv, &options);
	if (start == -1 || start == argc)
		error_exit(&a, &b);
	init_stack(&a, argc, argv, start);
	prepare_benchmark(&bench, a, &options);
	run_strategy(&a, &b, &options, &bench);
	if (options.bench)
		benchmark_print(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
