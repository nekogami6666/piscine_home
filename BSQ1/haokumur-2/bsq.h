/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@42.fr>                          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/02 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>

/*
** s_mapinfo:
** Holds map data and DP info for BSQ.
*/
typedef struct s_mapinfo
{
	int		rows;
	int		cols;
	char	**map;
	int		**dp;
	char	empty_c;
	char	obst_c;
	char	full_c;
	int		max_size;
	int		max_i;
	int		max_j;
}	t_mapinfo;

/*
** Global prototypes
*/
int		read_map(char *filename, t_mapinfo *info);
int		read_first_line(int fd, t_mapinfo *info);
int		read_map_body(int fd, t_mapinfo *info);

int		solve_bsq(t_mapinfo *info);
int		fill_and_print(t_mapinfo *info);
void	free_mapinfo(t_mapinfo *info);

#endif
