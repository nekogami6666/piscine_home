/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:20:40 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 18:21:37 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_strcmp(char *s1, char *s2)
// {
// 	while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*s1 - *s2);
// }

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*temp;

	if (tab == 0 || cmp == 0)
		return ;
	i = 0;
	while (tab[i] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (cmp(tab[i], tab[j]) > 0)
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

// int	main(void)
// {
// 	char	*tab[5];
// 	int		i;

// 	tab[0] = "banana";
// 	tab[1] = "apple";
// 	tab[2] = "cherry";
// 	tab[3] = "date";
// 	tab[4] = 0;
// 	i = 0;
// 	write(1, "Before sorting:\n", 16);
// 	while (tab[i] != 0)
// 	{
// 		write(1, tab[i], ft_strlen(tab[i]));
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	ft_advanced_sort_string_tab(tab, ft_strcmp);
// 	i = 0;
// 	write(1, "\nAfter sorting:\n", 16);
// 	while (tab[i] != 0)
// 	{
// 		write(1, tab[i], ft_strlen(tab[i]));
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	return (0);
// }
