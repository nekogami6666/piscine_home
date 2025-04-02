/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
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

 char	*alloc_and_copy(char *buf, int length)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line)
		return ((void *)0);
	i = 0;
	while (i < length)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

 char	*read_line(int fd)
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
			break ;
	}
	if (r <= 0 && i == 0)
		return ((void *)0);
	buf[i] = '\0';
	return (alloc_and_copy(buf, i));
}

/*
** read_map_body:
** - Reads info->rows lines, each line stored in info->map[i].
** - Updates info->cols accordingly, returns 0 or -1.
*/
int	read_map_body(int fd, t_mapinfo *info)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	while (i < info->rows)
	{
		line = read_line(fd);
		if (!line)
			return (-1);
		len = 0;
		while (line[len])
			len++;
		if (info->cols < len)
			info->cols = len;
		info->map[i] = line;
		i++;
	}
	return (0);
}
