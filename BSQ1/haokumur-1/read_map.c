/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:48:38 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:50:50 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>  // for open()
#include <unistd.h> // for close(), read()

/*
** parse_first_line:
**   - Interprets the first line (e.g. "9.ox") to get rows + chars.
**   - Returns 0 if OK, -1 if error.
*/
static int	parse_first_line(char *line, t_mapinfo *info)
{
	int	i;

	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (-1);
	info->rows = 0;
	while (*line >= '0' && *line <= '9')
	{
		info->rows = info->rows * 10 + (*line - '0');
		line++;
	}
	if (!*(line + 2))
		return (-1);
	info->empty_c = *line;
	info->obst_c = *(line + 1);
	info->full_c = *(line + 2);
	return (0);
}

/*
** read_first_line:
**   - Reads characters from fd until newline, stores them in buf.
**   - Then calls parse_first_line() to fill info.
*/
static int	read_first_line(int fd, t_mapinfo *info)
{
	char	buf[1024];
	int		i;
	int		r;

	i = 0;
	while ((r = read(fd, &buf[i], 1)) > 0)
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			break ;
		}
		i++;
	}
	if (r <= 0)
		return (-1);
	return (parse_first_line(buf, info));
}

/*
** allocate_map:
**   - Allocates info->map (but not each row's content).
**   - Initializes info->cols to 0 for later use.
*/
static int	allocate_map(t_mapinfo *info)
{
	int	i;

	info->map = (char **)malloc(sizeof(char *) * info->rows);
	if (!info->map)
		return (-1);
	i = 0;
	while (i < info->rows)
	{
		info->map[i] = NULL;
		i++;
	}
	info->cols = 0;
	return (0);
}

/*
** alloc_and_copy:
**   - Helper to allocate a string of length+1 and copy buf into it.
*/
static char	*alloc_and_copy(char *buf, int length)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (length + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < length)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
** read_line:
**   - Reads one line from fd (until '\n' or EOF).
**   - Returns a newly allocated string. If no data read, returns NULL.
*/
static char	*read_line(int fd)
{
	char	buf[1024];
	int		i;
	int		r;

	i = 0;
	while ((r = read(fd, &buf[i], 1)) > 0)
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			break ;
		}
		i++;
	}
	if (r <= 0 && i == 0)
		return (NULL);
	buf[i] = '\0';
	return (alloc_and_copy(buf, i));
}

/*
** read_map_body:
**   - Reads 'rows' lines. Each line is stored in info->map[i].
**   - Also updates info->cols to track the max column width.
*/
static int	read_map_body(int fd, t_mapinfo *info)
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

/*
** read_map:
**   - Opens filename (or uses fd=0 if filename==NULL).
**   - Reads first line (rows, chars), allocates map, reads map body.
**   - Closes file if opened. Returns 0 if OK, -1 if error.
*/
int	read_map(char *filename, t_mapinfo *info)
{
	int	fd;
	int	ret;

	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	else
		fd = 0;
	ret = read_first_line(fd, info);
	if (ret == -1 || allocate_map(info) == -1)
		return (-1);
	if (read_map_body(fd, info) == -1)
		return (-1);
	if (filename)
		close(fd);
	return (0);
}
