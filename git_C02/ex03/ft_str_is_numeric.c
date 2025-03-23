/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:39:38 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/17 18:49:24 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test1: \"1234\" => %d\n", ft_str_is_numeric("1234")); // 期待: 1
// 	printf("Test2: \"12ab\" => %d\n", ft_str_is_numeric("12ab")); // 期待: 0
// 	printf("Test3: \"\" => %d\n", ft_str_is_numeric(""));         // 期待: 1
// 	return (0);
// }
