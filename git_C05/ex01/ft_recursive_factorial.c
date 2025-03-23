/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:39:30 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/20 19:58:26 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>

// int main()
// {
//     printf("5! = %d\n", ft_recursive_factorial(5));   // 5! = 120
//     printf("0! = %d\n", ft_recursive_factorial(0));   // 0! = 1
//     printf("1! = %d\n", ft_recursive_factorial(1));   // 1! = 1
//     printf("-1! = %d\n", ft_recursive_factorial(-1)); // -1! = 0 (無効)
//     return 0;
// }
