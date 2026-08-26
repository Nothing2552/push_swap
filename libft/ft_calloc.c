/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:48:13 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/26 18:04:11 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*d;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (__SIZE_MAX__) / size)
	{
		return (NULL);
	}
	d = malloc(nmemb * size);
	if (!d)
	{
		return (NULL);
	}
	ft_bzero(d, nmemb * size);
	return (d);
}
