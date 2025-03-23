/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:44:04 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 18:04:08 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

// #include <unistd.h>

// void	ft_putnbr(int nb);
// void	ft_putchar(char c);

// // テスト用ヘルパー関数
// void	ft_putchar_newline(void)
// {
//     ft_putchar('\n');
// }

// int	main(void)
// {
//     ft_putnbr(42);
//     ft_putchar_newline();
//     ft_putnbr(-42);
//     ft_putchar_newline();
//     ft_putnbr(0);
//     ft_putchar_newline();
//     ft_putnbr(2147483647);
//     ft_putchar_newline();
//     ft_putnbr(-2147483648);
//     ft_putchar_newline();
//     return (0);
// }
