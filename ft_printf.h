/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:59 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/14 19:32:29 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *str, int *i);
//void	ft_putnbr(int nb, int *i);
void	ft_putchar(char c, int *i);
//void	ft_formu(unsigned int nb, int *i);
void	ft_choose(char format, int nb, int *i);
void	ft_check_format(char format, va_list arg, int *i);
void	ft_put_hex(char format, unsigned long nb, int *i);
//void	ft_put_pointer(unsigned long nb, int *i);

#endif
