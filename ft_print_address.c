/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:24 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/29 21:47:28 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

void	ft_print_address(void *p, int *count)
{
	size_t	nb;
	int		len;
	char	*hex;
	int		mod;

	nb = (size_t)p;
	len = ft_count_char(nb) + 2;
	hex = (char *)malloc((len + 1) * sizeof(char));
	if (!hex)
		return ;
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
	ft_putstr(hex,count);
	free(hex);
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
