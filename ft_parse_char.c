/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:58:07 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:03:50 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, int *printed)
{
	write(1, &c, 1);
	(*printed)++;
}

void	ft_parce_char(va_list args, int *printed)
{
	char	c;

	c = va_arg(args, int);
	ft_print_char(c, printed);
}
