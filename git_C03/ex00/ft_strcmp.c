/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:54:55 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 15:47:43 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = "HeLLo";
// 	int		result;

// 	result = ft_strcmp(str1, str2);
// 	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, result);
// 	// 予想としては 'l'(ASCII:108) - 'L'(ASCII:76) = 32 となります。
// 	return (0);
// }
