/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_print_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:18:38 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:20:07 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_word(char *key, t_dict_entry *dict, int dict_size, int *first_word)
{
	char	*word;

	word = find_word(dict, dict_size, key);
	if (!word)
		return (-1);
	if (!(*first_word))
		ft_putchar(' ');
	ft_putstr(word);
	*first_word = 0;
	return (0);
}

int	print_scale(int remaining_chunks, t_dict_entry *dict, int dict_size,
		int *first_word)
{
	char	*scale_key;
	char	*scale_word;
	int		res;

	scale_key = get_scale_key(remaining_chunks * 3);
	res = 0;
	if (!scale_key)
		return (-1);
	scale_word = find_word(dict, dict_size, scale_key);
	free(scale_key);
	if (!scale_word)
		return (-1);
	if (!(*first_word))
		ft_putchar(' ');
	ft_putstr(scale_word);
	*first_word = 0;
	return (res);
}
