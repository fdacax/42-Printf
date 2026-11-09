/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:02:17 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:01:30 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_ptr(va_list args, int *printed)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == 0)
	{
		ft_print_str("(nil)", printed);
		return ;
	}
	ft_print_str("0x", printed);
	ft_hex_putnbr((unsigned long)ptr, 'x', printed);
}
