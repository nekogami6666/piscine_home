/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:00 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 11:02:41 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テストとして、-1 から 10 までの ft_fibonacci の結果を出力してみる
// 	// index が負のときは -1 が返ることも確認できる
// 	for (int i = -1; i <= 10; i++)
// 	{
// 		printf("ft_fibonacci(%d) = %d\n", i, ft_fibonacci(i));
// 	}
// 	return (0);
// }
