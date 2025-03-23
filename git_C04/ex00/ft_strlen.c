/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:43:30 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 16:59:45 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>

// int	ft_strlen(char *str);

// int	main(void)
// {
// 	char *test_str = "Hello World!";
// 	printf("%d\n", ft_strlen(test_str)); // 結果が 12 になればOK
// 	return (0);
// }
