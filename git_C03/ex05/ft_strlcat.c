/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:48:18 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 10:09:00 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	i = 0;
	while (src[i] && (dlen + i) < size - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>
// int main(void)
// {
//     char dest[20] = "Hello";
//     char src[] = " 42Tokyo";
//     unsigned int size = 10;
//     unsigned int result;
//
//     result = ft_strlcat(dest, src, size);
//     printf("After ft_strlcat:\n");
//     printf("dest  = %s\n", dest);
//     printf("result= %u\n", result);
//     return (0);
// }
