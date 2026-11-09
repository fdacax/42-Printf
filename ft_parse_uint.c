/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:02:03 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:04:17 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_unsigned_putnbr(unsigned int nb, int *printed)
{
	if (nb > 9)
		ft_unsigned_putnbr((nb / 10), printed);
	ft_print_char (((nb % 10) + 48), printed);
}

void	ft_parse_uint(va_list args, int *printed)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_unsigned_putnbr(nbr, printed);
}
