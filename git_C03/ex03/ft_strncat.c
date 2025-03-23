/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:19:43 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 10:28:58 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char			dest[50] = "Hello"; // 連結先の文字列
	char			src[] = "World!";    // 連結元の文字列
	unsigned int	nb = 3;             // コピーする最大文字数
	printf("Before ft_strncat:\n");
	printf(" dest = \"%s\"\n", dest);
	printf(" src  = \"%s\"\n", src);
	ft_strncat(dest, src, nb);
	printf("\nAfter ft_strncat (nb = %u):\n", nb);
	printf(" dest = \"%s\"\n", dest);
	return (0);
}
*/

/*
[ 実行結果の例 ]

Before ft_strncat:
 dest = "Hello"
 src  = "World!"

After ft_strncat (nb = 3):
 dest = "HelloWor"

"Hello" に "Wor" (srcの先頭3文字) が連結されて、
最終的に "HelloWor" が表示されます。
*/
