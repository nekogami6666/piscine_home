/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:48:56 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:50:58 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
** allocate_dp:
**   - Allocates the dp 2D array with dimensions rows x cols.
*/
static int	allocate_dp(t_mapinfo *info)
{
	int	i;

	info->dp = (int **)malloc(sizeof(int *) * info->rows);
	if (!info->dp)
		return (-1);
	i = 0;
	while (i < info->rows)
	{
		info->dp[i] = (int *)malloc(sizeof(int) * info->cols);
		if (!info->dp[i])
			return (-1);
		i++;
	}
	return (0);
}

/*
** min3:
**   - Returns the minimum among three integers.
*/
static int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

/*
** fill_cell:
**   - Sets dp[i][j] based on adjacent cells (dynamic programming).
*/
static void	fill_cell(t_mapinfo *info, int i, int j)
{
	if (info->map[i][j] == info->obst_c)
		info->dp[i][j] = 0;
	else if (i == 0 || j == 0)
		info->dp[i][j] = 1;
	else
	{
		info->dp[i][j] = 1 + min3(info->dp[i - 1][j], info->dp[i][j - 1],
				info->dp[i - 1][j - 1]);
	}
}

/*
** update_max:
**   - Checks if dp[i][j] is bigger than current max_size, and updates if so.
*/
static void	update_max(t_mapinfo *info, int i, int j)
{
	if (info->dp[i][j] > info->max_size)
	{
		info->max_size = info->dp[i][j];
		info->max_i = i;
		info->max_j = j;
	}
}

/*
** fill_dp:
**   - Loops over each cell (i, j) to fill dp. Also tracks the max.
*/
static void	fill_dp(t_mapinfo *info)
{
	int	i;
	int	j;

	info->max_size = 0;
	info->max_i = 0;
	info->max_j = 0;
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

/*
** solve_bsq:
**   - Allocates dp, fills it via DP approach, returns 0 if OK, -1 if error.
*/
int	solve_bsq(t_mapinfo *info)
{
	if (allocate_dp(info) == -1)
		return (-1);
	fill_dp(info);
	return (0);
}
