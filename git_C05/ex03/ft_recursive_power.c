/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:51 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 10:57:39 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	result;

// 	result = ft_recursive_power(2, 3);
// 	printf("2^3 = %d\n", result);
// 	result = ft_recursive_power(3, 0);
// 	printf("3^0 = %d\n", result);
// 	result = ft_recursive_power(0, 0);
// 	printf("0^0 = %d\n", result);
// 	result = ft_recursive_power(2, -3);
// 	printf("2^-3 = %d\n", result);
// 	return (0);
// }
