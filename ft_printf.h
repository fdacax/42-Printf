/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 13:50:17 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:05:43 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

void	ft_print_char(char c, int *printed);
void	ft_print_str(char *str, int *printed);
void	ft_hex_putnbr(unsigned long nb, char hex_format, int *printed);

void	ft_parce_char(va_list args, int *printed);
void	ft_parse_int(va_list args, int *printed);
void	ft_parse_uint(va_list args, int *printed);
void	ft_parse_str(va_list args, int *printed);
void	ft_parse_hex(va_list args, char hex_format, int *printed);
void	ft_parse_ptr(va_list args, int *printed);

#endif