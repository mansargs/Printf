/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:24 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/30 22:55:57 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_print_address(void *p)
{
	size_t	nb;
	int		len;
	char	*hex;
	int		mod;
	int		count;

	nb = (size_t)p;
	len = ft_hex_char(nb) + 2;
	hex = (char *)malloc((len + 1) * sizeof(char));
	if (!hex)
		return (-1);
	hex[0] = '0';
	hex[1] = 'x';
	hex[len] = '\0';
	while (--len > 1)
	{
		mod = nb % 16;
		if (mod > 9)
			hex[len] = mod + 87;
		else
			hex[len] = mod + 48;
		nb /= 16;
	}
	count = ft_putstr(hex);
	free(hex);
	return (count);
}
/*
int main ()
{
	int k;
	k = 12;
	int *p = &k;
	printf("my pointer address --------> %p", p);
	ft_putaddress(p);
	return (0);
}
*/
