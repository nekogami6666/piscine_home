/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:37:08 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 19:55:57 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}

// #include <stdio.h> // printf等を使用するため

// int	main(void)
// {
// 	int	*range;
// 	int	size;
// 	int	i;

// 	// [3, 8) -> 3, 4, 5, 6, 7 が入るはず
// 	size = ft_ultimate_range(&range, 3, 8);
// 	printf("size: %d\n", size);
// 	if (size > 0 && range != NULL)
// 	{
// 		for (i = 0; i < size; i++)
// 			printf("range[%d] = %d\n", i, range[i]);
// 		free(range);
// 	}
// 	// minとmaxが同じ場合 -> 要素数0、rangeはNULL
// 	size = ft_ultimate_range(&range, 10, 10);
// 	printf("\nsize: %d (min = max = 10)\n", size);
// 	if (size == 0 && range == NULL)
// 		printf("range is NULL as expected.\n");
// 	// min > maxの場合 -> 要素数0、rangeはNULL
// 	size = ft_ultimate_range(&range, 5, 3);
// 	printf("\nsize: %d (min = 5, max = 3)\n", size);
// 	if (size == 0 && range == NULL)
// 		printf("range is NULL as expected.\n");
// 	return (0);
// }
