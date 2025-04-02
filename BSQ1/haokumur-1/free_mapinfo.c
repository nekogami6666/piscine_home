/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:49:14 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:49:15 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
** free_mapinfo:
**   - Frees all allocated memory inside t_mapinfo: map rows, dp rows, etc.
*/
void	free_mapinfo(t_mapinfo *info)
{
	int	i;

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
