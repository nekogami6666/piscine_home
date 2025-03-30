/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shraruki <sharuki@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:18:52 by shraruki          #+#    #+#             */
/*   Updated: 2025/03/30 20:18:57 by shraruki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char *itoa_basic(int n) {
    char buffer[12];
    int i;
    int is_neg;

    if (n == 0)
        return (ft_strdup("0"));
    i = 10;
    is_neg = n < 0;
    if (is_neg)
        n = -n;
    buffer[11] = '\0';
    while (n > 0) {
        buffer[i--] = (n % 10) + '0';
        n /= 10;
    }
    if (is_neg)
        buffer[i--] = '-';
    return (ft_strdup(&buffer[i + 1]));
}

char *get_scale_key(int num_zeros) {
    char *key;
    int i;

    if (num_zeros < 0)
        return (NULL);
    if (num_zeros == 0)
        return (ft_strdup("1"));
    key = (char *) malloc(num_zeros + 2);
    if (!key)
        return (NULL);
    key[0] = '1';
    i = 1;
    while (i <= num_zeros) {
        key[i] = '0';
        i++;
    }
    key[i] = '\0';
    return (key);
}