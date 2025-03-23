/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:31:48 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/17 17:32:11 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "HelloWorld";
// 	char	dest[20];

// 	dest[0] = '\0';
// 	printf("Before copy:\n");
// 	printf("  src  = \"%s\"\n", src);
// 	printf("  dest = \"%s\"\n\n", dest);
// 	ft_strcpy(dest, src);
// 	printf("After copy:\n");
// 	printf("  src  = \"%s\"\n", src);
// 	printf("  dest = \"%s\"\n", dest);
// 	return (0);
// }
