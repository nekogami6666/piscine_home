/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:52:49 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 09:48:03 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alphanumeric(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word_start;

	i = 0;
	is_word_start = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			if (is_word_start == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (is_word_start == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			is_word_start = 0;
		}
		else
			is_word_start = 1;
		i++;
	}
	return (str);
}

// // 実行結果は以下が期待されます : "Salut,
//	Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un"

// #include <stdio.h>

// 								int
// 								main(void)
// {
// 	char	test2[] = "heLLo worlD 42TOKYO YOU42 42yOu";

// 	char test1[] = "salut,comment tu vas? 42mots quarante - deux;cinquante + et
//		+ un ";
// 		printf("Before: %s\n", test1);
// 	ft_strcapitalize(test1);
// 	printf("After : %s\n\n", test1);
// 	printf("Before: %s\n", test2);
// 	ft_strcapitalize(test2);
// 	printf("After : %s\n", test2);
// 	return (0);
// }
