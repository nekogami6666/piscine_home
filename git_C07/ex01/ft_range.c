/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:36:59 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 19:55:52 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>

// int main()
// {
//     int min = 1, max = 5;
//     int *arr = ft_range(min, max);

//     // 配列の出力
//     if (arr != NULL)
//     {
//         for (int i = 0; i < max - min; i++)
//         {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");

//         // mallocで確保したメモリを解放
//         free(arr);
//     }
//     else
//     {
//         printf("NULL returned\n");
//     }

//     return (0);
// }
