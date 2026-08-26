/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aryaprak <aryaprak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/12 14:42:14 by aryaprak         #+#    #+#              */
/*   Updated: 2026/08/26 20:10:12 by aryaprak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_words_count(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	in_word;

	words = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}

static size_t	find_word_len(char const *s, char c, size_t j)
{
	size_t	chars;

	chars = 0;
	while (s[j] && s[j] != c)
	{
		chars++;
		j++;
	}
	return (chars);
}

static void	clear_all(char **d)
{
	size_t	j;

	j = 0;
	if (!d)
		return ;
	while (d[j])
	{
		free(d[j]);
		j++;
	}
	free(d);
}

static char	*fill_word(char const *s, char c, size_t *j)
{
	char	*word;
	size_t	word_len;

	while (s[*j] && s[*j] == c)
		(*j)++;
	word_len = find_word_len(s, c, *j);
	word = (char *) malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*j], word_len + 1);
	*j += word_len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	size_t	i;
	size_t	j;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = find_words_count(s, c);
	d = (char **) ft_calloc((word_count + 1), sizeof(char *));
	if (!d)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		d[i] = fill_word(s, c, &j);
		if (!d[i])
		{
			clear_all(d);
			return (NULL);
		}
		i++;
	}
	return (d);
}
