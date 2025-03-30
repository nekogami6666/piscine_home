/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:33:46 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 19:41:09 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char			*dict_path;
	char			*num_str;
	t_dict_entry	*dictionary;
	int				dict_size;

	if (argc < 2 || argc > 3)
	{
		print_error("Error");
		return (1);
	}
	if (argc == 2)
	{
		dict_path = "numbers.dict";
		num_str = argv[1];
	}
	else
	{
		dict_path = argv[1];
		num_str = argv[2];
	}
	if (!is_numeric(num_str))
	{
		print_error("Error");
		return (1);
	}
	dictionary = load_dictionary(dict_path, &dict_size);
	if (!dictionary)
	{
		return (1);
	}
	convert_number(num_str, dictionary, dict_size);
	free_dictionary(dictionary, dict_size);
	return (0);
}
