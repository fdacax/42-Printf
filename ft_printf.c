/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:07:59 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:05:13 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *str, va_list args, int *printed)
{
	str++;
	if (*str == 'c')
		ft_parce_char(args, printed);
	if (*str == 'd' || *str == 'i')
		ft_parse_int(args, printed);
	if (*str == 'u')
		ft_parse_uint(args, printed);
	if (*str == 's')
		ft_parse_str(args, printed);
	if (*str == 'x' || *str == 'X')
		ft_parse_hex(args, *str, printed);
	if (*str == 'p')
		ft_parse_ptr(args, printed);
	if (*str == '%')
		ft_print_char('%', printed);
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, str);
	printed = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_check_flag(&str[i++], args, &printed);
		else
			ft_print_char(str[i], &printed);
		i++;
	}
	va_end(args);
	return (printed);
}

/* 
va_start
va_arg
va_copy
va_end
 */