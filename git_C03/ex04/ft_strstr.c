/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:26:22 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/20 17:50:37 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] && to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

//  #include <stdio.h>
//  int main(void)
//  {
// 		char str[] = "Hello, world!";
// 		char to_find1[] = "world";
// 		char to_find2[] = "42";
// 		char to_find3[] = "";
// 		char *result;

// 		// テスト1: "world" を検索
// 		result = ft_strstr(str, to_find1);
// 			if (result)
// 			printf("Found '%s' in '%s': %s\n", to_find1, str, result);
// 		else
// 			printf("Substring '%s' not found in '%s'\n", to_find1, str);

// 		// テスト2: "42" を検索
// 		result = ft_strstr(str, to_find2);
// 		if (result)
// 			printf("Found '%s' in '%s': %s\n", to_find2, str, result);
// 		else
// 			printf("Substring '%s' not found in '%s'\n", to_find2, str);

// 		// テスト3: 空文字列 "" を検索 -> str をそのまま返すはず
// 		result = ft_strstr(str, to_find3);
// 		if (result)
// 			printf("Empty string search returns the original: %s\n", result);
// 		else
// 			printf("Something went wrong with empty string search.\n");

// 		return (0);
//  }
