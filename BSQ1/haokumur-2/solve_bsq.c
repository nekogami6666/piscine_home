/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

 int	allocate_dp(t_mapinfo *info)
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

 void	fill_dp(t_mapinfo *info);

int	solve_bsq(t_mapinfo *info)
{
	if (!info || info->rows <= 0)
		return (-1);
	if (allocate_dp(info) == -1)
		return (-1);
	fill_dp(info);
	return (0);
}
