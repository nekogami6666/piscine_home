/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:59:37 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/28 14:32:52 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_repeat(char c)
{
	int	repeat;

	repeat = 1;
	if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	return (repeat);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	repeat;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			repeat = ft_repeat(argv[1][i]);
			j = 0;
			while (j < repeat)
			{
				write(1, &argv[1][i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, '\n', 1);
}
