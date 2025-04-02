/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:03:14 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 15:24:33 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	rec_putnbr(long nb)
{
	char	c;

	if (nb > 9)
	{
		rec_putnbr(nb / 10);
		rec_putnbr(nb % 10);
	}
	else
	{
		c = (char)(nb + '0');
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	rec_putnbr(n);
}
