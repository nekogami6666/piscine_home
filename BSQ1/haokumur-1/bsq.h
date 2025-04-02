/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:48:09 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/02 17:48:10 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>

/*
** s_mapinfo:
** Holds map data, DP array, and other information needed by the BSQ project.
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
** Function prototypes
*/
int		handle_map(char *filename);
int		read_map(char *filename, t_mapinfo *info);
int		solve_bsq(t_mapinfo *info);
int		fill_and_print(t_mapinfo *info);
void	free_mapinfo(t_mapinfo *info);

#endif
