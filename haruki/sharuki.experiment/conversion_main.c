/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:17:59 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:27:00 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "conversion_print_chunk.h"
#include "conversion_print_utils.h"

void	convert_chunk(char *chunk_str, t_dict_entry *dict, int dict_size,
		int *first_word_printed, int remaining_chunks, int *error_flag)
{
	int	chunk_val;
	int	print_res;
	int	scale_res;

	if (*error_flag)
		return ;
	chunk_val = atoi(chunk_str);
	if (chunk_val > 0)
	{
		print_res = print_chunk(chunk_val, dict, dict_size, first_word_printed);
		if (print_res == -1)
		{
			*error_flag = 1;
			return ;
		}
		if (remaining_chunks > 0)
		{
			scale_res = print_scale(remaining_chunks, dict, dict_size,
					first_word_printed);
			if (scale_res == -1)
			{
				*error_flag = 1;
				return ;
			}
		}
	}
}

void	convert_number_recursive(char *num_str, int index, int num_chunks,
		int *chunk_lengths, t_dict_entry *dict, int dict_size,
		int *first_word_printed, int *error_flag)
{
	int		current_chunk_len;
	char	chunk_str_buf[4];
	int		k;

	if (*error_flag)
		return ;
	if (index >= num_chunks)
		return ;
	current_chunk_len = chunk_lengths[index];
	k = 0;
	while (k < current_chunk_len)
	{
		chunk_str_buf[k] = num_str[index == 0 ? k : chunk_lengths[0] + (index
				- 1) * 3 + k];
		k++;
	}
	chunk_str_buf[k] = '\0';
	convert_chunk(chunk_str_buf, dict, dict_size, first_word_printed, num_chunks
		- 1 - index, error_flag);
	convert_number_recursive(num_str, index + 1, num_chunks, chunk_lengths,
		dict, dict_size, first_word_printed, error_flag);
}

void	handle_zero(t_dict_entry *dict, int dict_size)
{
	char	*zero_word;

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
}

void	remove_leading_zeros(const char *num_str_in, char **num_str_out)
{
	int	i;

	i = 0;
	while (num_str_in[i] == '0' && num_str_in[i + 1] != '\0')
		i++;
	*num_str_out = (char *)&num_str_in[i];
}

void	calculate_chunk_lengths(int len, int **chunk_lengths_out,
		int *num_chunks_out)
{
	int	first_chunk_len;

	first_chunk_len = len % 3;
	if (first_chunk_len == 0)
		first_chunk_len = 3;
	*num_chunks_out = (len + 2) / 3;
	*chunk_lengths_out = (int *)malloc(*num_chunks_out * sizeof(int));
	if (*chunk_lengths_out == NULL)
		return ;
	(*chunk_lengths_out)[0] = first_chunk_len;
	for (int i = 1; i < *num_chunks_out; i++)
	{
		(*chunk_lengths_out)[i] = 3;
	}
}

void	convert_number(char *num_str_in, t_dict_entry *dict, int dict_size)
{
	if (ft_strcmp(num_str_in, "0") == 0)
	{
		handle_zero(dict, dict_size);
		return ;
	}

	char *num_str;
	remove_leading_zeros(num_str_in, &num_str);
	int len = ft_strlen(num_str);
	int *chunk_lengths;
	int num_chunks;
	calculate_chunk_lengths(len, &chunk_lengths, &num_chunks);

	int first_word_printed = 1;
	int error_flag = 0;

	convert_number_recursive(num_str, 0, num_chunks, chunk_lengths, dict,
		dict_size, &first_word_printed, &error_flag);

	free(chunk_lengths);

	if (error_flag)
		print_error("Dict Error");
	else if (len > 0)
		ft_putchar('\n');
}