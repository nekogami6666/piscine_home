/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:21 by haokumur          #+#    #+#             */
/*   Updated: 2025/04/01 15:23:49 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	find_op(char *op)
{
	int		i;
	t_op	ops[5];

	i = 0;
	ops[0].op_str = "+";
	ops[0].op_func = &add;
	ops[1].op_str = "-";
	ops[1].op_func = &sub;
	ops[2].op_str = "*";
	ops[2].op_func = &mul;
	ops[3].op_str = "/";
	ops[3].op_func = &divi;
	ops[4].op_str = "%";
	ops[4].op_func = &mod;
	while (i < 5)
	{
		if (ops[i].op_str[0] == op[0] && op[1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	handle_invalid_op(int idx)
{
	if (idx == -1)
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (1);
	}
	return (0);
}

int	handle_zero_div(int idx, int b)
{
	if (b == 0 && (idx == 3 || idx == 4))
	{
		if (idx == 3)
			ft_putstr("Stop : division by zero\n");
		else
			ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

int	handle_do_op(char *a_str, char *op_str, char *b_str)
{
	int		a;
	int		b;
	int		idx;
	t_op	ops[5];

	a = ft_atoi(a_str);
	b = ft_atoi(b_str);
	idx = find_op(op_str);
	ops[0].op_func = &add;
	ops[1].op_func = &sub;
	ops[2].op_func = &mul;
	ops[3].op_func = &divi;
	ops[4].op_func = &mod;
	if (handle_invalid_op(idx))
		return (0);
	if (handle_zero_div(idx, b))
		return (0);
	ft_putnbr(ops[idx].op_func(a, b));
	ft_putstr("\n");
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	handle_do_op(argv[1], argv[2], argv[3]);
	return (0);
}
