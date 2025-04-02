/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
** free_mapinfo:
** - Frees info->map and info->dp
*/
void	free_mapinfo(t_mapinfo *info)
{
	int	i;

	if (!info)
		return ;
	if (info->map)
	{
		i = 0;
		while (i < info->rows)
		{
			if (info->map[i])
				free(info->map[i]);
			i++;
		}
		free(info->map);
	}
	if (info->dp)
	{
		i = 0;
		while (i < info->rows)
		{
			if (info->dp[i])
				free(info->dp[i]);
			i++;
		}
		free(info->dp);
	}
}
