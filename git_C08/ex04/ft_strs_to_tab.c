/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:49:18 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/26 11:51:35 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_free_tab(t_stock_str *tab, int i)
{
	int	j;

	j = i - 1;
	while (j >= 0)
	{
		free(tab[j].copy);
		j--;
	}
	free(tab);
}

t_stock_str	*ft_handle_empty(void)
{
	t_stock_str	*tab;

	tab = malloc(sizeof(t_stock_str));
	if (tab)
		tab[0].str = NULL;
	return (tab);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = 0;
	if (ac <= 0 || !av)
		return (ft_handle_empty());
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
		{
			ft_free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
