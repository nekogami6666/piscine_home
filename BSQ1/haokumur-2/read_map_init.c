/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

 int	parse_first_line(char *buf, t_mapinfo *info)
{
	int	i;

	i = 0;
	info->rows = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		info->rows = info->rows * 10 + (buf[i] - '0');
		i++;
	}
	if (info->rows <= 0 || !buf[i] || !buf[i + 1] || !buf[i + 2])
		return (-1);
	info->empty_c = buf[i];
	info->obst_c = buf[i + 1];
	info->full_c = buf[i + 2];
	return (0);
}

 int	allocate_map(t_mapinfo *info)
{
	int	i;

	info->map = (char **)malloc(sizeof(char *) * info->rows);
	if (!info->map)
		return (-1);
	i = 0;
	while (i < info->rows)
	{
		info->map[i] = (void *)0;
		i++;
	}
	info->dp = (void *)0;
	info->cols = 0;
	info->max_size = 0;
	info->max_i = 0;
	info->max_j = 0;
	return (0);
}

/*
** read_first_line:
** - Reads the first line from fd, parse to fill info, allocate map.
** - Returns 0 or -1.
*/
int	read_first_line(int fd, t_mapinfo *info)
{
	char	buf[1024];
	int		i;
	int		r;

	i = 0;
	while ((r = read(fd, &buf[i], 1)) > 0)
	{
		if (buf[i] == '\n')
			break ;
		i++;
		if (i >= 1023)
			return (-1);
	}
	if (r <= 0 || i == 0)
		return (-1);
	buf[i] = '\0';
	if (parse_first_line(buf, info) == -1)
		return (-1);
	return (allocate_map(info));
}
