/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:38:26 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/30 22:53:50 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	swich_case(char c, va_list args, int *count)
{
	int len;

	if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (c == 's')
	{
		*count += ft_putstr(va_arg(args, char *));
	}

	else if (c == 'p')
		*count += ft_print_address(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
	{
		len = ft_putnbr(va_arg(args, int));
		if (len == -1)
			return (-1);
		*count += len;
	}
	else if (c == 'u')
	{
		len = ft_putnbr(va_arg(args, unsigned int));
		if (len == -1)
			return (-1);
		*count += len;
	}
	else if (c == 'x' || c == 'X')
		*count += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
	{
		write(1,"%", 1);
		++*count;
	}
	else
		return (-1);
	return (0);
}

int ft_printf(const char *s, ...)
{
	int	i;
	int	count;
	va_list args;

	i = 0;
	count = 0;
	va_start(args,s);
	while(s[i])
	{
		while (s[i] != '%' && s[i])
		{
			count += ft_putchar(s[i]);
			++i;
		}
		if (s[i] == '%')
		{
			++i;
			if (s[i] == '\0')
			{
				write(1,"Error: Incomplete format specifier\n", 34);
				return (-1);
			}
			if (swich_case(s[i], args, &count) == -1)
			{
				write(1,"Error: Incomplete format specifier\n", 34);
				return (-1);
			}
			++i;
		}
	}
	return (count);
}
/*
#include <stdio.h>

int main ()
{
	printf("printf result is ----->%d\n", printf("%x is\t", 0));
	ft_printf("ft_printf result is ----->%d\n", ft_printf("%x is\t", 0));
	return (0);

}
*/
