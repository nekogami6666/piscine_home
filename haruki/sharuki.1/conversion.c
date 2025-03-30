/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:33:23 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 19:28:44 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*itoa_basic(int n)
{
	char	buffer[12];
	int		i;
	int		is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	i = 10;
	is_neg = n < 0;
	if (is_neg)
		n = -n;
	buffer[11] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		buffer[i--] = '-';
	return (ft_strdup(&buffer[i + 1]));
}

int	print_chunk(int num, t_dict_entry *dict, int dict_size, int *first_word)
{
	char	*key_str;
	char	*word;
	int		printed_something;
	char	*unit_word;

	printed_something = 0;
	if (num == 0)
		return (0);
	if (num >= 100)
	{
		key_str = itoa_basic(num / 100);
		word = find_word(dict, dict_size, key_str);
		free(key_str);
		if (!word)
			return (-1);
		if (!(*first_word))
			ft_putchar(' ');
		ft_putstr(word);
		*first_word = 0;
		printed_something = 1;
		word = find_word(dict, dict_size, "100");
		if (!word)
			return (-1);
		ft_putchar(' ');
		ft_putstr(word);
		num %= 100;
	}
	if (num > 0)
	{
		if (printed_something && !(*first_word))
			ft_putchar(' ');
		if (num < 20)
		{
			key_str = itoa_basic(num);
			word = find_word(dict, dict_size, key_str);
			free(key_str);
		}
		else
		{
			key_str = itoa_basic((num / 10) * 10);
			word = find_word(dict, dict_size, key_str);
			free(key_str);
			if (!word && num % 10 != 0)
				return (-1);
			if (word)
			{
				if (!(*first_word))
					ft_putchar(' ');
				ft_putstr(word);
				*first_word = 0;
				printed_something = 1;
			}
			if (num % 10 != 0)
			{
				key_str = itoa_basic(num % 10);
				unit_word = find_word(dict, dict_size, key_str);
				free(key_str);
				if (!unit_word)
					return (-1);
				if (word)
					ft_putchar(' ');
				else if (!(*first_word))
					ft_putchar(' ');
				ft_putstr(unit_word);
				*first_word = 0;
				printed_something = 1;
			}
			word = NULL;
		}
		if (word)
		{
			if (!(*first_word))
				ft_putchar(' ');
			ft_putstr(word);
			*first_word = 0;
			printed_something = 1;
		}
		else if (!printed_something && num > 0)
		{
			return (-1);
		}
	}
	return (printed_something > 0);
}

char	*get_scale_key(int num_zeros)
{
	char	*key;
	int		i;

	if (num_zeros < 0)
		return (NULL);
	if (num_zeros == 0)
		return (ft_strdup("1"));
	key = (char *)malloc(num_zeros + 2);
	if (!key)
		return (NULL);
	key[0] = '1';
	i = 1;
	while (i <= num_zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

void	convert_number(char *num_str_in, t_dict_entry *dict, int dict_size)
{
	char	*num_str;
	int		len;
	int		first_chunk_len;
	int		num_chunks;
	int		i;
	int		first_word_printed;
	int		error_flag;
	char	*zero_word;
	int		current_chunk_len;
		char chunk_str_buf[4];
	int		k;
	int		chunk_val;
	int		print_res;
	int		remaining_chunks;
	char	*scale_key;
	char	*scale_word;

	error_flag = 0;
	if (ft_strcmp(num_str_in, "0") == 0)
	{
		zero_word = find_word(dict, dict_size, "0");
		if (zero_word)
		{
			ft_putstr(zero_word);
			ft_putchar('\n');
		}
		else
		{
			print_error("Dict Error");
		}
		return ;
	}
	i = 0;
	while (num_str_in[i] == '0' && num_str_in[i + 1] != '\0')
		i++;
	num_str = &num_str_in[i];
	len = ft_strlen(num_str);
	first_chunk_len = len % 3;
	if (first_chunk_len == 0)
		first_chunk_len = 3;
	num_chunks = (len + 2) / 3;
	first_word_printed = 1;
	i = 0;
	while (i < num_chunks && !error_flag)
	{
		current_chunk_len = (i == 0) ? first_chunk_len : 3;
		k = 0;
		while (k < current_chunk_len)
		{
			chunk_str_buf[k] = num_str[i * 3 + (i == 0 ? 0 : first_chunk_len
					- 3) + k];
			k++;
		}
		chunk_str_buf[k] = '\0';
		chunk_val = 0;
		k = 0;
		while (chunk_str_buf[k])
		{
			chunk_val = chunk_val * 10 + (chunk_str_buf[k] - '0');
			k++;
		}
		if (chunk_val > 0)
		{
			print_res = print_chunk(chunk_val, dict, dict_size,
					&first_word_printed);
			if (print_res == -1)
			{
				error_flag = 1;
				break ;
			}
			remaining_chunks = num_chunks - 1 - i;
			if (remaining_chunks > 0)
			{
				scale_key = get_scale_key(remaining_chunks * 3);
				if (!scale_key)
				{
					error_flag = 1;
					break ;
				}
				scale_word = find_word(dict, dict_size, scale_key);
				free(scale_key);
				if (!scale_word)
				{
					error_flag = 1;
					break ;
				}
				if (!first_word_printed)
					ft_putchar(' ');
				ft_putstr(scale_word);
				first_word_printed = 0;
			}
		}
		i++;
	}
	if (error_flag)
		print_error("Dict Error");
	else
		ft_putchar('\n');
}
