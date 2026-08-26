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

static char	**get_new_argv(int argc, char **argv, int *new_argc)
{
	char	**split;
	char	**res;
	int		i;

	if (argc != 2)
		return (*new_argc = argc, argv);
	split = ft_split(argv[1], ' ');
	if (!split)
		return (NULL);
	*new_argc = 0;
	while (split[*new_argc])
		(*new_argc)++;
	res = malloc(sizeof(char *) * (*new_argc + 2));
	if (!res)
		return (ft_free_split(split), NULL);
	res[0] = argv[0];
	i = 0;
	while (i < *new_argc)
	{
		res[i + 1] = split[i];
		i++;
	}
	res[*new_argc + 1] = NULL;
	(*new_argc)++;
	return (free(split), res);
}

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
	if (argc == 2)
	{
		while (--new_argc > 0)
			free(new_argv[new_argc]);
		free(new_argv);
	}
	if (!result)
		return (1);
	return (0);
}
