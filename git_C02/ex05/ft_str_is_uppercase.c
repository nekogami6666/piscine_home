/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:16:46 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:44:58 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	// 1. 大文字のみ
	printf("Test 1: \"ABC\" -> %d\n", ft_str_is_uppercase("ABC"));
	// 期待結果: 1
	// 2. 小文字が含まれる
	printf("Test 2: \"AbC\" -> %d\n", ft_str_is_uppercase("AbC"));
	// 期待結果: 0
	// 3. 数字や記号が含まれる
	printf("Test 3: \"AB1C\" -> %d\n", ft_str_is_uppercase("AB1C"));
	// 期待結果: 0
	// 4. 空文字
	printf("Test 4: \"\" -> %d\n", ft_str_is_uppercase(""));
	// 期待結果: 1
	// 5. A～Z 全部
	printf("Test 5: \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\" -> %d\n",
		ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	// 期待結果: 1
	return (0);
}
*/
