/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   check_args.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 21:24:09 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:13:13 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_to_nbr(int *i, long *number, const char *str, int sign)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			return (0);
		*number = *number * 10 + (str[*i] - '0');
		if ((sign == 1 && *number > 2147483647)
			|| (sign == -1 && *number > 2147483648))
			return (0);
		(*i)++;
	}
}

int	parse_int(const char *str, int *result)
{
	long	number;
	int		sign;
	int		i;

	if (!str || !str[0] || !result)
		return (0);
	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	if (str_to_nbr(&i, &number, str, sign))
		return (0);
	*result = (int)(number * sign);
	return (1);
}

int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
