/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haokumur <haokumur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:25:42 by haokumur          #+#    #+#             */
/*   Updated: 2025/03/18 13:35:47 by haokumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hex_byte(unsigned char c)
{
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

static void	print_address(unsigned long long addr)
{
	char	b[16];
	int		i;

	i = 15;
	while (i >= 0)
	{
		b[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, b, 16);
}

static void	print_hex_pair(const unsigned char *ptr, unsigned int i,
		unsigned int size)
{
	if (i < size)
		print_hex_byte(ptr[i]);
	else
		write(1, "  ", 2);
	if (i + 1 < size)
		print_hex_byte(ptr[i + 1]);
	else
		write(1, "  ", 2);
	write(1, " ", 1);
}

static void	print_line(unsigned long long addr, unsigned int size,
		const unsigned char *ptr)
{
	unsigned int	i;
	unsigned int	g;

	print_address(addr);
	write(1, ": ", 2);
	g = 0;
	while (g < 8)
	{
		print_hex_pair(ptr, g * 2, size);
		g++;
	}
	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] < 127)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i < 16)
			len = size - i;
		else
			len = 16;
		print_line((unsigned long long)(ptr + i), len, ptr + i);
		i += 16;
	}
	return (addr);
}

//  #include <stdio.h>
//  int	main(void)
//  {
//  	char str[] = "Bonjour les amiches\09\0a\09c\07 est fou.tout.ce qu on "
//  				"peut faire avec.\0a\09print_memory\0a\0a\nLol.lol\n ";
// 	ft_print_memory(str, sizeof(str));
//  	return (0);
//  }
