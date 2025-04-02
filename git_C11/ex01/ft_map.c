/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:51:41 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 11:23:28 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	if (length <= 0 || tab == NULL)
		return (NULL);
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

// #include <stdio.h>

// int	multiply_by_two(int n)
// {
// 	return (n * 2);
// }

// int	main(void)
// {
// 	int	original[] = {1, 2, 3, 4, 5};
// 	int	length;
// 	int	*mapped;
// 	int	i;

// 	length = 5;
// 	// ft_mapを呼び出して、各要素を2倍にした新しい配列を受け取る
// 	mapped = ft_map(original, length, multiply_by_two);
// 	if (mapped == NULL)
// 	{
// 		printf("Error: Failed to allocate memory or invalid length.\n");
// 		return (1);
// 	}
// 	printf("Original array: ");
// 	for (i = 0; i < length; i++)
// 	{
// 		printf("%d ", original[i]);
// 	}
// 	printf("\n");
// 	printf("Mapped array:   ");
// 	for (i = 0; i < length; i++)
// 	{
// 		printf("%d ", mapped[i]);
// 	}
// 	printf("\n");
// 	// mallocで確保した領域を開放
// 	free(mapped);
// 	return (0);
// }
