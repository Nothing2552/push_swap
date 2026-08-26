/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_free_split.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/26 18:18:34 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:10:05 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **d)
{
	size_t	j;

	if (!d)
		return ;
	j = 0;
	while (d[j])
	{
		free(d[j]);
		j++;
	}
	free(d);
}
