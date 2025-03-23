/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:12:58 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/20 19:57:32 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// テストケース
// 	int test1 = 0;
// 	int test2 = 1;
// 	int test3 = 5;
// 	int test4 = -3;

// 	printf("Factorial of %d = %d\n", test1, ft_iterative_factorial(test1));
// 	printf("Factorial of %d = %d\n", test2, ft_iterative_factorial(test2));
// 	printf("Factorial of %d = %d\n", test3, ft_iterative_factorial(test3));
// 	printf("Factorial of %d = %d\n", test4, ft_iterative_factorial(test4));
// 	return (0);
// }
