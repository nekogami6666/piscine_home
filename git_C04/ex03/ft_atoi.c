/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:44:16 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/19 17:52:44 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

// #include <stdio.h>

// int ft_atoi(char *str);

// int main(void)
// {
//     char *test_cases[] = {
//         "1234",
//         "   5678",
//         "+42",
//         "-42",
//         "++--42",
//         "  -+--1234ab567",
//         "abc42",
//         NULL
//     };
//     for (int i = 0; test_cases[i] != NULL; i++)
//     {
//         printf("ft_atoi(\"%s\") = %d\n", test_cases[i],
//         ft_atoi(test_cases[i]));
	//     }
	//     return (0);
	// }
