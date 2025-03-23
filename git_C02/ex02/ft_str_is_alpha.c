/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:13:13 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/17 17:38:40 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A'
				&& str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	ft_str_is_alpha(char *str);

// int	main(void)
// {
// 	/* テストケース */
// 	printf("Test 1 (\"Hello\"): %d\n", ft_str_is_alpha("Hello"));     // 1
// 	printf("Test 2 (\"Hello42\"): %d\n", ft_str_is_alpha("Hello42")); // 0
// 	printf("Test 3 (\"42\"): %d\n", ft_str_is_alpha("42"));           // 0
// 	printf("Test 4 (\"abcdEFG\"): %d\n", ft_str_is_alpha("abcdEFG")); // 1
// 	printf("Test 5 (\" \"): %d\n", ft_str_is_alpha(" "));             // 0
// 	printf("Test 6 (\"!\"): %d\n", ft_str_is_alpha("!"));             // 0
// 	printf("Test 7 (\"\"): %d\n", ft_str_is_alpha(""));
// 	// 1 (空文字列は1を返す)
// 	return (0);
// }
