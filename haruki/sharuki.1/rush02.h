/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:30:54 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:09:39 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict_entry
{
	char		*key;
	char		*value;
}				t_dict_entry;

void			ft_putstr(char *str);
void			ft_putchar(char c);
void			print_error(char *msg);

int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src);
int				ft_is_space(char c);
int				ft_is_printable(char c);
char			*trim_whitespace(char *str);
char			*ft_strndup(char *src, int n);

int				is_numeric(char *str);
int				validate_dict_line(char *line, char **key, char **value);

t_dict_entry	*load_dictionary(char *path, int *dict_size);
char			*find_word(t_dict_entry *dict, int dict_size, char *key);
void			free_dictionary(t_dict_entry *dict, int dict_size);
char			*read_file_content(int fd, char *path);

void			convert_number(char *num_str, t_dict_entry *dict,
					int dict_size);

#endif