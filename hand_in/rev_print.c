/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:20:41 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/28 18:29:02 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	temp;

	len = str_len(argv[1]);
	if (argc == 2)
	{
		i = 0;
		while (i < (len / 2))
		{
			temp = argv[1][i];
			argv[1][i] = argv[1][len - 1 - i];
			argv[1][len - 1 - i] = temp;
			i++;
		}
		i = 0;
		while (i < len)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
