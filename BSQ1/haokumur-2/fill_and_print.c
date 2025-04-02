/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

 void	fill_square(t_mapinfo *info)
{
	int	i;
	int	j;
	int	start_i;
	int	start_j;

	start_i = info->max_i - info->max_size + 1;
	start_j = info->max_j - info->max_size + 1;
	i = 0;
	while (i < info->max_size)
	{
		j = 0;
		while (j < info->max_size)
		{
			info->map[start_i + i][start_j + j] = info->full_c;
			j++;
		}
		i++;
	}
}

int	fill_and_print(t_mapinfo *info)
{
	int	i;
	int	j;

	fill_square(info);
	i = 0;
	while (i < info->rows)
	{
		j = 0;
		while (j < info->cols)
		{
			write(1, &info->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
