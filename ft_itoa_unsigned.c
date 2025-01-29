/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:31:28 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/29 20:50:37 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_char(unsigned int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		num /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int num)
{
	int		len;
	char	*str;

	len = count_char(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + len) = '\0';
	while (len > 0)
	{
		*(str + len - 1) = (num % 10) + '0';
		num = num / 10;
		--len;
	}
	return (str);
}
