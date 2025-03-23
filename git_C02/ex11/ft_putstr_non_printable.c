/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:49:02 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:54:27 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[2];

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			hex[0] = "0123456789abcdef"[str[i] / 16];
			hex[1] = "0123456789abcdef"[str[i] % 16];
			ft_putchar(hex[0]);
			ft_putchar(hex[1]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("Coucou\ntu vas bien ?");
// 	return (0);
// }
