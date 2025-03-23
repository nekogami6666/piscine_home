/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:31:31 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/16 20:20:19 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_first = 1;

void	ft_combn_recur(char *digits, int level, int start, int n)
{
	int	i;

	if (level == n)
	{
		if (!g_first)
			write(1, ", ", 2);
		else
			g_first = 0;
		write(1, digits, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		digits[level] = '0' + i;
		ft_combn_recur(digits, level + 1, i + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	digits[10];

	if (n <= 0 || n >= 10)
		return ;
	g_first = 1;
	ft_combn_recur(digits, 0, 0, n);
}
