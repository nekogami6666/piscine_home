/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:32:16 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:04:40 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_dict_line(char *line, char **key, char **value)
{
	char *colon_pos;
	char *key_start;
	char *value_start;
	int key_len;

	key_start = line;
	while (*key_start && ft_is_space(*key_start))
		key_start++;
	colon_pos = key_start;
	while (*colon_pos && *colon_pos != ':')
		colon_pos++;
	if (*colon_pos != ':')
		return (1);
	value_start = colon_pos + 1;
	key_len = 0;
	while (key_start + key_len < colon_pos && (key_start[key_len] >= '0'
			&& key_start[key_len] <= '9'))
		key_len++;
	char *ptr = key_start + key_len;
	while (ptr < colon_pos)
	{
		if (!ft_is_space(*ptr))
			return (1);
		ptr++;
	}
	if (key_len == 0)
		return (1);
	*key = ft_strndup(key_start, key_len);
	if (!*key)
		return (1);

	char *raw_value = trim_whitespace(value_start);
	if (!raw_value)
	{
		free(*key);
		return (1);
	}
	if (ft_strlen(raw_value) == 0)
	{
		free(*key);
		free(raw_value);
		return (1);
	}

	int i = 0;
	while (raw_value[i])
	{
		if (!ft_is_printable(raw_value[i]))
		{
			free(*key);
			free(raw_value);
			return (1);
		}
		i++;
	}
	*value = raw_value;
	return (0);
}