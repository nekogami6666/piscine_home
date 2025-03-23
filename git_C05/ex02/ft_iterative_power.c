/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:41 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/20 20:07:18 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int main() {
//     printf("%d\n", ft_iterative_power(2, 3));  // 8
//     printf("%d\n", ft_iterative_power(5, 0));  // 1
//     printf("%d\n", ft_iterative_power(3, -2)); // 0
//     printf("%d\n", ft_iterative_power(7, 4));  // 2401
//     return 0;
// }
