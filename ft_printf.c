/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:38:26 by mansargs          #+#    #+#             */
/*   Updated: 2025/02/02 19:16:50 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	next_case(const char c, va_list args, int *count, int len)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (c != 'u')
			len = print_number(va_arg(args, int));
		len = print_number(va_arg(args, unsigned int));
		if (len == -1)
			return (-1);
		*count += len;
	}
	else if (c == 'x' || c == 'X')
	{
		len = ft_print_hex(va_arg(args, unsigned int), c);
		if (len == -1)
			return (-1);
		*count += len
	}
	else if (c == '%')
	{
		write(1,"%", 1);
		++*count;
	}
	else
		return (-1);
	return (0);
}

static int	swich_case(const char c, va_list args, int *count)
{
	int len;

	if (c == 'c')
		*count += print_symbol(va_arg(args, int));
	else if (c == 's')
	{
		len = print_string(va_arg(args, char *));
		if (len == -1)
			return (-1);
		*count += len;
	}
	else if (c == 'p')
	{
		len = print_pointer(va_arg(args, void *));
		if (len == -1)
			return (-1);
		*count += len;
	}
	else if (next_cases(c, args, count, &len) == -1)
		return (-1);
	return (0);
}

int ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	while (s && *s)
	{
		count = 0;
		va_start(args,s);
		if (*s == '%')
		{
			++s;
			if (*s == '\0' || swich_case(*s, args, &count) == -1)
			{
				write(1,"Error: Incomplete format specifier or alloacation failed\n", 56);
				return (-1);
			}
			++s;
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
