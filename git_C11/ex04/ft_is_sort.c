/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:51:48 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 11:51:43 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	if (length <= 2)
		return (1);
	ascending = 1;
	descending = 1;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			ascending = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			descending = 0;
		i++;
	}
	if (ascending || descending)
		return (1);
	return (0);
}

// #include <stdio.h>

// // 比較用関数の例: a - b (標準的な昇順ソート用)
// int	cmp(int a, int b)
// {
// 	return (a - b);
// }

// int	main(void)
// {
// 	int	tab1[] = {1, 2, 3, 4, 5};
// 	int	tab2[] = {5, 4, 3, 2, 1};
// 	int	tab3[] = {1, 3, 2, 4, 5};

// 	int tab4[] = {42}; // 要素数1の例
// 	printf("tab1 is sorted? => %d\n", ft_is_sort(tab1, 5, &cmp));
// 	printf("tab2 is sorted? => %d\n", ft_is_sort(tab2, 5, &cmp));
// 	printf("tab3 is sorted? => %d\n", ft_is_sort(tab3, 5, &cmp));
// 	printf("tab4 is sorted? => %d\n", ft_is_sort(tab4, 1, &cmp));
// 	return (0);
// }
