/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansargs <mansargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:44:06 by mansargs          #+#    #+#             */
/*   Updated: 2025/01/29 21:48:40 by mansargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(const char c, int *count);
void	ft_putstr(const char *s, int *count);
int		ft_count_char(size_t num);
void	ft_print_address(void *p, int *count);
char	*ft_itoa(int num);
char	*ft_itoa_unsigned(unsigned int num);
void	ft_print_hex(unsigned int num, char c, int *count);
int		ft_printf(const char *s, ...);

#endif
