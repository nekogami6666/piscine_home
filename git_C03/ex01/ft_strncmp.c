/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:48:08 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 20:57:48 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char			*str1;
	char			*str2;
	unsigned int	n;
	int				result1;
	int				result2;

	str1 = "Hello";
	str2 = "Hello, World!";
	// 比較パターン1: n=5（"Hello"を5文字まで比較する）
	n = 5;
	result1 = ft_strncmp(str1, str2, n);
	printf("ft_strncmp(\"%s\", \"%s\", %u) = %d\n",
			str1, str2, n, result1);
	// -> 先頭5文字が同じなので、結果は0となるはずです。
	// 比較パターン2: n=6（"Hello"と"Hello,"を6文字目まで比較する）
	n = 6;
	result2 = ft_strncmp(str1, str2, n);
	printf("ft_strncmp(\"%s\", \"%s\", %u) = %d\n",
			str1, str2, n, result2);
	// -> 5文字目は 'o' (ASCII:111) と ',' (ASCII:44) の次の比較になります。
	//    str1は6文字目が '\0' (ASCII:0)
	//    str2は6文字目が ',' (ASCII:44)
	//    よって 0 - 44 = -44 となり負の値が返るはずです。
	return (0);
}
*/
