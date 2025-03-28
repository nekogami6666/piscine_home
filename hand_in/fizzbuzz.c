/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:27:21 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/28 17:58:46 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnb(int nb)
{
	int	digit;

	if (nb > 9)
		putnb(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 != 0)
			write(1, "fizz", 4);
		else if (i % 3 != 0 && i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else
			putnb(i);
		write(1, "\n", 1);
		i++;
	}
}
