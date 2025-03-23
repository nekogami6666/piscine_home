/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:54:20 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:43:31 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test1: \"1234\" => %d\n", ft_str_is_lowercase("1234")); // 期待: 0
// 	printf("Test2: \"12ab\" => %d\n", ft_str_is_lowercase("12ab")); // 期待: 0
// 	printf("Test3: \"\" => %d\n", ft_str_is_lowercase(""));         // 期待: 1
// 	return (0);
// }
