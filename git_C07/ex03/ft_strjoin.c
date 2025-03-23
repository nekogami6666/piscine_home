/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:37:16 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 20:05:59 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_calc_len(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	if (size <= 0)
		return (0);
	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * (size - 1);
	return (total);
}

static void	ft_join_strs(char *res, int size, char **strs, char *sep)
{
	int	i;
	int	offset;
	int	sep_len;
	int	len;

	sep_len = ft_strlen(sep);
	offset = 0;
	i = 0;
	while (i < size)
	{
		len = ft_strlen(strs[i]);
		ft_strcpy(res + offset, strs[i]);
		offset += len;
		if (i < size - 1)
		{
			ft_strcpy(res + offset, sep);
			offset += sep_len;
		}
		i++;
	}
	res[offset] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		total_len;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	total_len = ft_calc_len(size, strs, sep);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	ft_join_strs(res, size, strs, sep);
	return (res);
}

// #include <stdio.h>
// #include <unistd.h>
// int	main(void)
// {
// 	char	*strs[3];
// 	char	*sep;
// 	char	*joined;

// 	strs[0] = "Hello";
// 	strs[1] = "42Tokyo";
// 	strs[2] = "World";
// 	sep = " - ";

// 	joined = ft_strjoin(3, strs, sep);
// 	if (!joined)
// 		return (1);

// 	write(1, joined, ft_strlen(joined));
// 	write(1, "\n", 1);

// 	free(joined);
// 	return (0);
// }
