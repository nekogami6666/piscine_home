/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:17:30 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/17 19:48:11 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[10];

// 	strncpy(dest, "HelloWorld", 5);
// 	printf("Result: %s\n", dest); // 期待 "Hello"
// 	ft_strncpy(dest, "HelloWorld", 5);
// 	printf("Result: %s\n", dest); // 期待 "Hi"
// 	return (0);
// }
