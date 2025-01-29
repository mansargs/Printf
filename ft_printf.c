/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:38:26 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/29 22:01:01 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	swich_case(char c, va_list args, int *count)
{
	char	*str;

	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_print_address(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		ft_putstr(str, count);
		free (str);
	}
	else if (c == 'u')
	{
		str = ft_itoa_unsigned(va_arg(args, unsigned int));
		ft_putstr(str, count);
		free (str);
	}
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(args, unsigned int), c, count);
	else if (c == '%')
		write(1,"%", 1);
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
			ft_putchar(s[i], &count);
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
	printf("printf result is ----->%d\n", printf("%s is\t", "Hello"));
	ft_printf("ft_printf result is ----->%d\n", ft_printf("%s is\t", "Hello"));
	return (0);
}
*/
