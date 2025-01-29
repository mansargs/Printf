/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:41:56 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/29 21:49:10 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int num, char c, int *count)
{
	int		len;
	char	*hex;
	int		mod;

	if (c =='x')
		c = 87;
	else
		c = 55;
	len = ft_count_char(num) + 2;
	hex = (char *)malloc((len + 1) * sizeof(char));
	if (!hex)
		return ;
	hex[0] = '0';
	hex[1] = 'x';
	hex[len] = '\0';
	while (--len > 1)
	{
		mod = num % 16;
		if (mod > 9)
			hex[len] = mod + c;
		else
			hex[len] = mod + 48;
		num /= 16;
	}
	ft_putstr(hex, count);
	free(hex);
}
