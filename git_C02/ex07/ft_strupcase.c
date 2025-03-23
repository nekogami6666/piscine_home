/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:58:38 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:34:21 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char text1[] = "hello, world!";
	char text2[] = "42 Tokyo";
	char text3[] = "Already UPPER";
	char text4[] = "miXeD CaSe 1234";

	printf("Before: %s\n", text1);
	ft_strupcase(text1);
	printf("After : %s\n\n", text1);

	printf("Before: %s\n", text2);
	ft_strupcase(text2);
	printf("After : %s\n\n", text2);

	printf("Before: %s\n", text3);
	ft_strupcase(text3);
	printf("After : %s\n\n", text3);

	printf("Before: %s\n", text4);
	ft_strupcase(text4);
	printf("After : %s\n\n", text4);

	return (0);
}
*/
