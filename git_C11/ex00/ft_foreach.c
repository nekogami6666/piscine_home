/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:51:39 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 18:12:15 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	char	digit;

// 	if (nb == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb > 9)
// 		ft_putnbr(nb / 10);
// 	digit = nb % 10 + '0';
// 	write(1, &digit, 1);
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// 	myfunc = ft_putnbr;
// 	myfunc(123);
// 	ft_putchar('\n');
// 	ft_foreach(arr, 5, ft_putnbr);
// 	ft_putchar('\n'); // => 1020304050 (数字が連続で表示)
// 	ft_foreach(arr, 5, myfunc);
// 	ft_putchar('\n');
// 	return (0);
// }
