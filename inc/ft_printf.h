/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:49:22 by ozahid-           #+#    #+#             */
/*   Updated: 2021/12/26 21:06:08 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_unsignednumber(unsigned int nb);
int	ft_putnbr(long nb);
int	ft_putstr(char *str);
int	ft_hexa(unsigned int nb, char arg);
int	ft_argp(unsigned long nb);
int	ft_printf(const char *str, ...);

#endif
