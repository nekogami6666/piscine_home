/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:32:34 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 19:41:17 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#define BUFFER_SIZE 4096

char	*read_file_content(int fd, char *path)
{
	char	buffer[BUFFER_SIZE];
	char	*content;
	char	*new_content;
	int		bytes_read;
	int		total_size;
	int		i;
	int		j;

	(void)path;
	content = ft_strdup("");
	if (!content)
		return (NULL);
	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		new_content = (char *)malloc(total_size + bytes_read + 1);
		if (!new_content)
		{
			free(content);
			return (NULL);
		}
		i = 0;
		while (i < total_size)
		{
			new_content[i] = content[i];
			i++;
		}
		j = 0;
		while (j < bytes_read)
		{
			new_content[i + j] = buffer[j];
			j++;
		}
		new_content[total_size + bytes_read] = '\0';
		free(content);
		content = new_content;
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

char	**split_lines(char *text, int *line_count)
{
	int		count;
	char	**lines;
	char	*start;
	int		idx;

	count = 0;
	for (int i = 0; text[i]; ++i)
	{
		if (text[i] == '\n')
			count++;
	}
	if (ft_strlen(text) > 0 && text[ft_strlen(text) - 1] != '\n')
		count++;
	lines = (char **)malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (NULL);
	start = text;
	idx = 0;
	for (int i = 0; text[i]; ++i)
	{
		if (text[i] == '\n')
		{
			lines[idx] = ft_strndup(start, &text[i] - start);
			if (!lines[idx])
			{
				return (NULL);
			}
			idx++;
			start = &text[i + 1];
		}
	}
	if (*start)
	{
		lines[idx] = ft_strdup(start);
		if (!lines[idx])
		{
			return (NULL);
		}
		idx++;
	}
	lines[idx] = NULL;
	*line_count = idx;
	return (lines);
}

t_dict_entry	*load_dictionary(char *path, int *dict_size)
{
	int				fd;
	char			*file_content;
	char			**lines;
	t_dict_entry	*dict;
	int				i;
	int				entry_index;
	int				line_count_total;
	char			*trimmed_line;
			char *key;
			char *value;
	int				k;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_content = read_file_content(fd, path);
	close(fd);
	if (!file_content)
		return (NULL);
	lines = split_lines(file_content, &line_count_total);
	free(file_content);
	if (!lines)
		return (NULL);
	dict = (t_dict_entry *)malloc(sizeof(t_dict_entry) * line_count_total);
	if (!dict)
	{
		return (NULL);
	}
	i = 0;
	entry_index = 0;
	while (lines[i] != NULL)
	{
		trimmed_line = trim_whitespace(lines[i]);
		if (!trimmed_line)
		{
			return (NULL);
		}
		if (ft_strlen(trimmed_line) > 0)
		{
			if (validate_dict_line(trimmed_line, &key, &value) == 0)
			{
				dict[entry_index].key = key;
				dict[entry_index].value = value;
				entry_index++;
			}
			else
			{
				free(trimmed_line);
				free_dictionary(dict, entry_index);
				k = 0;
				while (lines[k])
					free(lines[k++]);
				free(lines);
				print_error("Dict Error");
				return (NULL);
			}
		}
		free(trimmed_line);
		free(lines[i]);
		i++;
	}
	free(lines);
	*dict_size = entry_index;
	return (dict);
}

char	*find_word(t_dict_entry *dict, int dict_size, char *key)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

void	free_dictionary(t_dict_entry *dict, int dict_size)
{
	int i;

	if (!dict)
		return ;
	i = 0;
	while (i < dict_size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}