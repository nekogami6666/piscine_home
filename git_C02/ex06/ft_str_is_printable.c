/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:44:35 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:46:23 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>  // デバッグ用に追加

int	main(void)
{
	char *test1 = "";             // 空文字列
	char *test2 = "HelloWorld!";  // 全て表示可能文字
	char *test3 = "Hello\tWorld"; // タブ(\t)が含まれる非表示文字
	char *test4 = "ABC 123";      // スペース含むが表示可能文字
	printf("Test1: \"%s\" -> %d\n", test1, ft_str_is_printable(test1));
	printf("Test2: \"%s\" -> %d\n", test2, ft_str_is_printable(test2));
	printf("Test3: \"%s\" -> %d\n", test3, ft_str_is_printable(test3));
	printf("Test4: \"%s\" -> %d\n", test4, ft_str_is_printable(test4));
	return (0);
}
*/
