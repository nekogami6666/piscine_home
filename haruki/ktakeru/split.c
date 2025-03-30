#include "header.h"

int	ft_is_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_size(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str + i, charset))
	{
		i++;
	}
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str && !ft_is_sep(str, charset))
		{
			words++;
			str += ft_word_size(str, charset);
		}
		while (*str && ft_is_sep(str, charset))
			str++;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * ft_count_words(str, charset) + 1);
	if (!res)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str && !ft_is_sep(str, charset))
		{
			res[i] = ft_strdup(str, ft_word_size(str, charset));
			if (!res[i])
				return (0);
			str += ft_word_size(str, charset);
			i++;
		}
		while (*str && ft_is_sep(str, charset))
			str++;
	}
	res[i] = 0;
	return (res);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**res;
	int		i;

	(void)argc;
	res = ft_split(argv[1], argv[2]);
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
*/
