/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaydilek <yaydilek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:18:34 by yaydilek          #+#    #+#             */
/*   Updated: 2026/08/26 18:18:48 by yaydilek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_split(char **d)
{
    size_t  j;

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