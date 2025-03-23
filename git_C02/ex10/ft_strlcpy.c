/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:30:10 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:35:32 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
//
// int main(void)
// {
//     char src[] = "Hello World!";
//     char dest[20];
//     unsigned int len;
//
//     // 1. dest のサイズ分コピーする例
//     len = ft_strlcpy(dest, src, sizeof(dest));
//     printf("[Test 1]\n");
//     printf("src:  %s\n", src);
//     printf("dest: %s\n", dest);
//     printf("return value (src_len): %u\n\n", len);
//
//     // 2. size が小さい場合の例
//     len = ft_strlcpy(dest, src, 5);
//     printf("[Test 2]\n");
//     printf("src:  %s\n", src);
//     printf("dest: %s\n", dest);
//     printf("return value (src_len): %u\n\n", len);
//
//     // 3. size = 0 の場合
//     len = ft_strlcpy(dest, src, 0);
//     printf("[Test 3]\n");
//     printf("src:  %s\n", src);
//     printf("dest: %s (実際はコピーされない)\n", dest);
//     printf("return value (src_len): %u\n", len);
//
//     return 0;
// }
