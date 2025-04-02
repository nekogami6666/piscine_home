/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:54:51 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/26 18:55:12 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (!is_charset(*str, charset) && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (is_charset(*str, charset))
			is_word = 0;
		str++;
	}
	return (count);
}

static char	*alloc_word(char *start, char *end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	skip_charset(char **p, char *charset)
{
	while (**p && is_charset(**p, charset))
		(*p)++;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;
	int		i;
	char	*start;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		skip_charset(&str, charset);
		start = str;
		while (*str && !is_charset(*str, charset))
			str++;
		result[i] = alloc_word(start, str);
		if (!result[i++])
			return (NULL);
	}
	result[i] = 0;
	return (result);
}
