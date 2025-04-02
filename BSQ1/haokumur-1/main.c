/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:48:25 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:48:26 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h> // for write()

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

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (handle_map(NULL));
	i = 1;
	while (i < argc)
	{
		handle_map(argv[i]);
		i++;
	}
	return (0);
}
