/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:06 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/30 23:02:55 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(const char c);
int		ft_putstr(const char *s);
int		ft_hex_char(size_t num);
int		ft_print_address(void *p);
int		ft_print_hex(unsigned int num, char c);
int		ft_putnbr(long num);
int		ft_printf(const char *s, ...);

#endif
