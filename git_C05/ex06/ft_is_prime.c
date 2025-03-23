/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:21 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 13:26:19 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	long	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h> // デバッグ時のみ使用

// int	main(void)
// {
// 	int test_values[] = {-1, 0, 1, 2, 3, 4, 9, 17, 25};
// 	int i;
// 	int result;

// 	i = 0;
// 	while (i < 9)
// 	{
// 		result = ft_is_prime(test_values[i]);
// 		printf("ft_is_prime(%d) = %d\n", test_values[i], result);
// 		i++;
// 	}
// 	return (0);
// }
