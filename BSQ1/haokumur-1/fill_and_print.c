/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:49:07 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:49:08 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

/*
** fill_square:
**   - Using max_size, max_i, max_j from info,
**     replaces the largest square area with full_c.
*/
static void	fill_square(t_mapinfo *info)
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

/*
** fill_and_print:
**   - Calls fill_square() to put 'full_c' in the solution area,
**     then prints the entire map to stdout.
*/
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
