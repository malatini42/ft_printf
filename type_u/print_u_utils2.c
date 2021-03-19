/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:51:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 15:08:32 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_zero_pad_then_number_precision_u(t_format * format, unsigned int number, char print)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (number == 0) ? 0 : n_size_u(number);
	precision_to_print = format->precision - len;
	if ((unsigned int)format->precision >=number)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	if (number > 0)
		ft_putnbr_u(number);
	i += number == 0 ? 0 : n_size_u(number);
	return (i);
}

int		print_width_and_precision_pos_u(t_format *format, unsigned int number, char print)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = (number > 0) ? format->precision - n_size_u(number) : format->precision;
	if (format->precision > n_size_u(number) && number > 0)
		width_to_print = format->width - precision_to_print - n_size_u(number);
	else if (number == 0)
		width_to_print = format->width - precision_to_print;
	else
		width_to_print = format->width - n_size_u(number);
	i = 0;
	if (format->flags.zero_pad == true)
		print = ' ';
	i += print_x_time(print, width_to_print);
	i += print_x_time('0', precision_to_print);
	if (number > 0)
	{
		ft_putnbr_u(number);
		i += n_size_u(number);
	}
	return (i);
}
