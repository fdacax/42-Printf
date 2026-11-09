/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedacax <fedacax@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:42:53 by fedacax           #+#    #+#             */
/*   Updated: 2026/10/14 13:04:36 by fedacax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *printed)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_print_char(str[i], printed);
		i++;
	}
}

void	ft_parse_str(va_list args, int *printed)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_print_str("(null)", printed);
		return ;
	}
	ft_print_str(str, printed);
}
