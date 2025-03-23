/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:40:12 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/21 11:04:39 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while ((long)i * i <= nb)
	{
		if ((long)i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     int numbers[] = {16, 17, 0, -1, 1, 2, 25, 26, 100, 101};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     int i;

//     for (i = 0; i < size; i++)
//     {
//         int result = ft_sqrt(numbers[i]);
//         printf("ft_sqrt(%d) -> %d\n\n", numbers[i], result);
//     }
//     return 0;
// }
