/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

/*
** read_map:
** - Opens filename or uses fd=0 if filename==NULL.
** - Calls read_first_line -> read_map_body.
** - Returns -1 if error, else 0.
*/
int	read_map(char *filename, t_mapinfo *info)
{
	int	fd;
	int	ret;

	if (!info)
		return (-1);
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	else
		fd = 0;
	ret = read_first_line(fd, info);
	if (ret == -1)
		return (-1);
	ret = read_map_body(fd, info);
	if (filename && fd > 0)
		close(fd);
	return (ret);
}
