/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:31:51 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:05:49 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	if (n < 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

char	*trim_whitespace(char *str)
{
	char *start;
	char *end;
	int len;
	char *trimmed_str;
	int i;

	if (!str)
		return (NULL);
	start = str;
	while (*start && ft_is_space(*start))
		start++;
	end = str + ft_strlen(str) - 1;
	while (end > start && ft_is_space(*end))
		end--;
	len = (end - start) + 1;
	if (len <= 0)
		return (ft_strdup(""));
	trimmed_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed_str[i] = start[i];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}