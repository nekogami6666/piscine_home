/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:30 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 13:28:12 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テストしたい値をいくつか用意して検証
// 	int test_values[] = { -1, 0, 1, 2, 3, 8, 11, 12, 14, 16,
// 17, 18, 19, 20, 2147483647 };
// 	int i;
// 	int size = sizeof(test_values) / sizeof(test_values[0]);

// 	i = 0;
// 	while (i < size)
// 	{
// 		int val = test_values[i];
// 		int next_prime = ft_find_next_prime(val);
// 		printf("Input: %d, Next prime: %d\n", val, next_prime);
// 		i++;
// 	}
// 	return (0);
// }
