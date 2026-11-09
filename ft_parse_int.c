/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:20:07 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:02:11 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_long_putnbr(long nb, int *printed)
{
	if (nb < 0)
	{
		ft_print_char('-', printed);
		nb = -nb;
	}
	if (nb > 9)
		ft_long_putnbr((nb / 10), printed);
	ft_print_char(((nb % 10) + 48), printed);
}

void	ft_parse_int(va_list args, int *printed)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_long_putnbr(nbr, printed);
}
