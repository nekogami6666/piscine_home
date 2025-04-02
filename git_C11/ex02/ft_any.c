/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:51:43 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 11:29:41 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	is_a(char *str)
// {
// 	// ここでは単に先頭文字が 'a' かをチェック
// 	if (str[0] == 'a')
// 		return (1);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*tab1[] = {"abc", "def", "ghi", NULL};
// 	char	*tab2[] = {"def", "ghi", "xyz", NULL};
// 	char	*tab3[] = {NULL};

// 	// テスト1: "abc"が含まれるので、is_a が1を返す要素が存在し、結果は1
// 	printf("Test1 -> %d\n", ft_any(tab1, &is_a));
// 	// テスト2: "a"で始まる要素が無いので結果は0
// 	printf("Test2 -> %d\n", ft_any(tab2, &is_a));
// 	// テスト3: 空の配列(NULLのみ)なので当然0
// 	printf("Test3 -> %d\n", ft_any(tab3, &is_a));
// 	return (0);
// }
