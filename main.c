/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:38:28 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:15:48 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prepare_benchmark(t_benchmark *bench, t_node *a, t_options *options)
{
	benchmark_init(bench);
	bench->disorder = compute_disorder(a);
	bench->strategy = options->strategy;
	bench->effective_strategy = options->strategy;
}

static void	run_strategy(t_node **a, t_node **b,
			t_options *options, t_benchmark *bench)
{
	if (options->strategy == STRATEGY_SIMPLE)
		sort_simple(a, b, bench);
	else if (options->strategy == STRATEGY_MEDIUM)
		sort_medium(a, b, bench);
	else if (options->strategy == STRATEGY_COMPLEX)
		sort_complex(a, b, bench);
	else
		sort_adaptive(a, b, bench);
}

static int	execute_sort(int new_argc, char **new_argv, t_options *options)
{
	t_node		*a;
	t_node		*b;
	t_benchmark	bench;
	int			start;

	a = NULL;
	b = NULL;
	start = parse_options(new_argc, new_argv, options);
	if (start == -1 || start == new_argc)
		return (write(2, "Error\n", 6), 0);
	if (!init_stack(&a, new_argc, new_argv, start))
	{
		free_stack(&a);
		return (write(2, "Error\n", 6), 0);
	}
	prepare_benchmark(&bench, a, options);
	run_strategy(&a, &b, options, &bench);
	if (options->bench)
		benchmark_print(&bench);
	free_stack(&a);
	free_stack(&b);
	return (1);
}

int	main(int argc, char **argv)
{
	char		**new_argv;
	int			new_argc;
	t_options	options;
	int			result;

	if (argc == 1)
		return (0);
	new_argv = get_new_argv(argc, argv, &new_argc);
	if (!new_argv)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	result = execute_sort(new_argc, new_argv, &options);
	free_new_argv(new_argv, new_argc);
	if (!result)
		return (1);
	return (0);
}
