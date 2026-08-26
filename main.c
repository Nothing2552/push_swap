/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:38:28 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/26 18:50:10 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:38:28 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/26 18:48:07 by yaydilek         ###   ########.fr       */
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
		return (free(split), NULL);
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

static void	prepare_benchmark(t_benchmark *bench, t_node *a,
                              t_options *options)
{
	benchmark_init(bench);
	bench->disorder = compute_disorder(a);
	bench->strategy = options->strategy;
}

static void	run_strategy(t_node **a, t_node **b, t_options *options,
                         t_benchmark *bench)
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

static void	execute_sort(int new_argc, char **new_argv, t_options *options)
{
	t_node		*a;
	t_node		*b;
	t_benchmark	bench;
	int			start;

	a = NULL;
	b = NULL;
	start = parse_options(new_argc, new_argv, options);
	if (start == -1 || start == new_argc)
		error_exit(&a, &b);
	init_stack(&a, new_argc, new_argv, start);
	prepare_benchmark(&bench, a, options);
	run_strategy(&a, &b, options, &bench);
	if (options->bench)
		benchmark_print(&bench);
	free_stack(&a);
	free_stack(&b);
}

int	main(int argc, char **argv)
{
	char		**new_argv;
	int			new_argc;
	t_options	options;

	if (argc == 1)
		return (0);
	new_argv = get_new_argv(argc, argv, &new_argc);
	if (!new_argv)
	{
		if (argc == 2)
			ft_free_split(new_argv);
		return (1);
	}
	execute_sort(new_argc, new_argv, &options);
	if (argc == 2)
		free(new_argv);
	return (0);
}
