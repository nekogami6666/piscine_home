/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:00 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 15:24:09 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

typedef struct s_op
{
	char	*op_str;
	int		(*op_func)(int, int);
}	t_op;

/* ---------------- */
/*  プロトタイプ群  */
/* ---------------- */

/* main.c */
int		find_op(char *op);
int		handle_invalid_op(int idx);
int		handle_zero_div(int idx, int b);
int		handle_do_op(char *a_str, char *op_str, char *b_str);

/* operations.c */
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		divi(int a, int b);
int		mod(int a, int b);

/* ft_atoi.c */
int		ft_atoi(char *str);

/* ft_putnbr.c */
void	ft_putnbr(int nb);

/* ft_putstr.c */
void	ft_putstr(char *str);

#endif
