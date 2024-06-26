/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:14:56 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/06 18:46:31 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *i)
{
	int	j;

	j = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*i = *i + 6;
		return ;
	}
	while (str[j])
	{
		write(1, &str[j], 1);
		*i = *i + 1;
		j++;
	}
}
