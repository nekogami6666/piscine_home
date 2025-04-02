/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

 int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

 void	fill_cell(t_mapinfo *info, int i, int j)
{
	if (info->map[i][j] == info->obst_c)
		info->dp[i][j] = 0;
	else if (i == 0 || j == 0)
		info->dp[i][j] = 1;
	else
		info->dp[i][j] = 1 + min3(info->dp[i - 1][j],
				info->dp[i][j - 1], info->dp[i - 1][j - 1]);
}

 void	update_max(t_mapinfo *info, int i, int j)
{
	if (info->dp[i][j] > info->max_size)
	{
		info->max_size = info->dp[i][j];
		info->max_i = i;
		info->max_j = j;
	}
}

 void	fill_dp(t_mapinfo *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->rows)
	{
		j = 0;
		while (j < info->cols)
		{
			fill_cell(info, i, j);
			update_max(info, i, j);
			j++;
		}
		i++;
	}
}
