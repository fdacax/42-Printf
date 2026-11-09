/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:23:29 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:02:41 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_putnbr(unsigned long nb, char hex_format, int *printed)
{
	char			*hex;
	unsigned int	i;

	if (hex_format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_hex_putnbr(nb / 16, hex_format, printed);
	i = nb % 16;
	ft_print_char(hex[i], printed);
}

void	ft_parse_hex(va_list args, char hex_format, int *printed)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_hex_putnbr(nb, hex_format, printed);
}
