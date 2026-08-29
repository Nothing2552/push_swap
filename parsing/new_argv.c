/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryaprak <aryaprak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:32:18 by aryaprak          #+#    #+#             */
/*   Updated: 2026/08/29 15:32:22 by aryaprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_new_argv(char **argv, int argc)
{
	while (--argc > 0)
		free(argv[argc]);
	free(argv);
}

static int	has_multiple_groups(int argc, char **argv)
{
	int	i;
	int	groups;
	int	j;

	i = 1;
	groups = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				groups++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (groups > 1);
}

static int	count_new_args(int argc, char **argv)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ft_free_split(split), -1);
		j = 0;
		while (split[j])
			j++;
		total += j;
		ft_free_split(split);
		i++;
	}
	return (total);
}

static int	append_split(char **res, int *position, char *arg)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		res[(*position)++] = split[i++];
	free(split);
	return (1);
}

char	**get_new_argv(int argc, char **argv, int *new_argc)
{
	char	**res;
	int		total;
	int		i;
	int		position;

	if (has_multiple_groups(argc, argv))
		return (NULL);
	total = count_new_args(argc, argv);
	if (total < 0)
		return (NULL);
	res = ft_calloc(total + 2, sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = argv[0];
	position = 1;
	i = 1;
	while (i < argc && append_split(res, &position, argv[i]))
		i++;
	if (i < argc)
		return (free_new_argv(res, position), NULL);
	*new_argc = position;
	return (res);
}
