/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:06:54 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 18:15:12 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// int	ft_strlen(char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char	*tab[5];
// 	int		i;

// 	tab[0] = "banana";
// 	tab[1] = "apple";
// 	tab[2] = "grape";
// 	tab[3] = "orange";
// 	tab[4] = 0;
// 	ft_sort_string_tab(tab);
// 	i = 0;
// 	while (tab[i] != 0)
// 	{
// 		ft_putstr(tab[i]);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	return (0);
// }
