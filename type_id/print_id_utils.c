/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:52:24 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 09:11:21 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//faire une fonction pour determiner la width en eviter les ternaires ?

//Pas utilisee finalement
int		print_pad_then_number(t_format *format, int number)
{
	int 	i;
	char 	to_print;
	int		width_to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	width_to_print = (format->width > n_size(number)) ? format->width - n_size(number) : 0;
	i += print_x_time(to_print, width_to_print);
	ft_putnbr(number);
	i += n_size(number);
	return (i);
}

int		print_zero_pad_then_number_width(t_format *format, int number, char print)
{
	int i;
	int len;
	int width_to_print;

	i = 0;
	len = n_size(number);
	width_to_print = format->width - len;
	if (format->width > number)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, width_to_print);
	ft_putnbr(number);
	i += n_size(number);
	return (i);
}

int		print_zero_pad_then_number_precision(t_format *format, int number, char print)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = n_size(number);
	precision_to_print = format->precision - len;
	if (format->precision > number)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	ft_putnbr(number);
	i += n_size(number);
	return (i);
}
//Faire une fonction qui fait l'inverse
