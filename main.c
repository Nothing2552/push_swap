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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_options	options;
	int		start;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	start = parse_options(argc, argv, &options);
	if (start == -1 || start == argc)
		error_exit(&a, &b);
	init_stack(&a, argc, argv, start);
	if (options.strategy == STRATEGY_SIMPLE)
		sort_simple(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
