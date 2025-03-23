/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:49:04 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:48:48 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	test1[] = "HELLO 42!";
	char	test2[] = "AlReAdY_LoWeRcAsE";
	char	test3[] = "MixedCASE123";

	printf("Before: %s\n", test1);
	ft_strlowcase(test1);
	printf("After : %s\n\n", test1);
	printf("Before: %s\n", test2);
	ft_strlowcase(test2);
	printf("After : %s\n\n", test2);
	printf("Before: %s\n", test3);
	ft_strlowcase(test3);
	printf("After : %s\n", test3);
	return (0);
}
*/
