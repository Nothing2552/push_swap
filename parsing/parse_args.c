/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_args.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 22:43:57 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/23 22:44:37 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_equal(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

static int	set_strategy(char *arg, t_options *options, int *is_set)
{
	if (*is_set)
		return (0);
	if (str_equal(arg, "--simple"))
		options->strategy = STRATEGY_SIMPLE;
	else if (str_equal(arg, "--medium"))
		options->strategy = STRATEGY_MEDIUM;
	else if (str_equal(arg, "--complex"))
		options->strategy = STRATEGY_COMPLEX;
	else if (str_equal(arg, "--adaptive"))
		options->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	*is_set = 1;
	return (1);
}

int	parse_options(int argc, char **argv, t_options *options)
{
	int	i;
	int	strategy_set;

	options->strategy = STRATEGY_ADAPTIVE;
	options->bench = 0;
	strategy_set = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (str_equal(argv[i], "--bench"))
		{
			if (options->bench)
				return (-1);
			options->bench = 1;
		}
		else if (!set_strategy(argv[i], options, &strategy_set))
			return (-1);
		i++;
	}
	return (i);
}
