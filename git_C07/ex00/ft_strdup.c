/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:36:40 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 20:04:36 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
// #include <unistd.h>
// int main()
// {
//     char *original = "Hello, World!";
//     char *duplicate = ft_strdup(original);
//     if (duplicate) {
//         write(1, duplicate, 13);
//         write(1, "\n", 1);
//         free(duplicate);  // メモリを解放
//     } else {
//         write(1, "Memory allocation failed\n", 24);
//     }
//     return (0);
// }
