/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:51:46 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 18:12:58 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < length && tab[i])
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// int	ft_str_is_not_empty(char *str)
// {
// 	if (str[0] == '\0')
// 		return (0);
// 	return (1);
// }

// void	ft_putnbr(int nb)
// {
// 	char	c;

// 	if (nb > 9)
// 		ft_putnbr(nb / 10);
// 	c = (nb % 10) + '0';
// 	write(1, &c, 1);
// }

// int	main(void)
// {
// 	char	*tab[] = {"Hello", "", "42", "Tokyo", "Osaka", NULL};
// 	int		result;
//
//
// 	result = ft_count_if(tab, 6, &ft_str_is_not_empty);
//
// 	ft_putnbr(result);
// 	write(1, "\n", 1);
// 	return (0);
// }
