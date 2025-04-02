/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** handle_map:
** - read_map -> solve_bsq -> fill_and_print -> free_mapinfo
*/
 int	handle_map(char *filename)
{
	t_mapinfo	info;
	int			ret;

	ret = read_map(filename, &info);
	if (ret == -1 || solve_bsq(&info) == -1)
	{
		write(2, "map error\n", 10);
		free_mapinfo(&info);
		return (-1);
	}
	fill_and_print(&info);
	free_mapinfo(&info);
	return (0);
}

/*
** main:
** - If no arguments, process from stdin. Otherwise handle each file.
*/
int			main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		handle_map((void *)0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		handle_map(argv[i]);
		i++;
	}
	return (0);
}
