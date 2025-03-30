/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_print_chunk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:18:28 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:19:03 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int print_single(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    char *key_str = itoa_basic(num);
    int res = print_word(key_str, dict, dict_size, first_word);
    free(key_str);
    return (res);
}

int print_ten(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    char *key_str = itoa_basic(num);
    int res = print_word(key_str, dict, dict_size, first_word);
    free(key_str);
    return (res);
}

int print_twenty_to_ninety(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    char *key_str = itoa_basic((num / 10) * 10);
    int res = print_word(key_str, dict, dict_size, first_word);
    free(key_str);
    return (res);
}

int print_under_hundred(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    int res;

    if (num < 10)
        res = print_single(num, dict, dict_size, first_word);
    else if (num < 20)
        res = print_ten(num, dict, dict_size, first_word);
    else {
        res = print_twenty_to_ninety((num / 10) * 10, dict, dict_size, first_word);
        if (num % 10 != 0 && res != -1)
            res = print_single(num % 10, dict, dict_size, first_word);
    }
    return (res);
}

int print_hundreds_chunk(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    int res;

    res = print_single(num / 100, dict, dict_size, first_word);
    if (res == -1)
        return (-1);
    ft_putchar(' ');
    res = print_word("100", dict, dict_size, first_word);
    if (res == -1)
        return (-1);
    res = print_under_hundred(num % 100, dict, dict_size, first_word);
    return (res);
}

int print_chunk(int num, t_dict_entry *dict, int dict_size, int *first_word) {
    int printed_something = 0;
    int res;

    if (num == 0)
        return (0);
    if (num >= 100) {
        res = print_hundreds_chunk(num, dict, dict_size, first_word);
        if (res == -1)
            return (-1);
        printed_something = 1;
    } else {
        res = print_under_hundred(num, dict, dict_size, first_word);
        if (res == -1 && num > 0)
            return (-1);
        printed_something = (num > 0);
    }
    return (printed_something);
}