/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:44:27 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 18:12:12 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;

	base_len = ft_strlen(base);
	if (!is_valid_base(base))
		return ;
	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= base_len)
	{
		ft_putnbr_base(nb / base_len, base);
	}
	write(1, &base[nb % base_len], 1);
}

// #include <stdio.h>  // printf 用

// void	ft_putnbr_base(int nbr, char *base);

// int	main(void)
// {
// 	printf("Test1 => expecting 123 (10進):\n");
// 	ft_putnbr_base(123, "0123456789");
// 	printf("\n\n");

// 	printf("Test2 => expecting FF (16進):\n");
// 	ft_putnbr_base(255, "0123456789ABCDEF");
// 	printf("\n\n");

// 	printf("Test3 => expecting 101 (2進):\n");
// 	ft_putnbr_base(5, "01");
// 	printf("\n\n");

// 	printf("Test4 => expecting ofe (poneyvif,8進相当で123):\n");
// 	ft_putnbr_base(123, "poneyvif");
// 	printf("\n\n");

// 	printf("Test5 => expecting -123 (10進):\n");
// 	ft_putnbr_base(-123, "0123456789");
// 	printf("\n\n");

// 	printf("Test6 => invalid base => 何も出力しないはず:\n");
// 	ft_putnbr_base(123, "012345+789"); // '+'含むので無効
// 	printf("\n(ここは空っぽが正解)\n");

// 	return (0);
// }
