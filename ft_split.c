/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:25 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:03:02 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

/*This function counts the number of words in a string delimited 
by a specified character.*/
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		s++;
	}
	return (count);
}

/*It deallocates memory allocated for the array of strings split*/
static void	free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
	free (split);
}

/*It processes each word in the string s, delimited by the character c, 
and stores them in the array split.*/
static int	treat_word(const char *s, char c, char **split, size_t word_count)
{
	const char	*start;
	size_t		len;
	size_t		i;

	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		len = s - start;
		split[i] = ft_substr(start, 0, len);
		if (!split[i])
		{
			free_split(split, i);
			return (0);
		}
		i++;
	}
	split[i] = NULL;
	return (1);
}

/*This function splits a string into an array of substrings 
based on a specified delimiter character.*/
char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	char		**split;

	if (!s || !c)
		return (0);
	word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (0);
	if (!treat_word(s, c, split, word_count))
		return (0);
	return (split);
}
