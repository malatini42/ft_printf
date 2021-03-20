/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:52:24 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:06:59 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_then_number(t_format *format, int number)
{
	int		i;
	char	to_print;
	int		width_to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	width_to_print = (format->width > n_size_i(number)) ? format->width - n_size_i(number) : 0;
	i += print_x_time(to_print, width_to_print);
	i += ft_putnbr_i(number);
	return (i);
}

int		print_zero_pad_then_number_precision_i(t_format *format, int number, char print)
{
	int i;
	int len;
	int precision_to_print;
	int num;

	i = 0;
	num = number;
	if (number < 0)
	{
		ft_putchar('-');
		num = -number;
		i++;
	}
	len = n_size_i(num);
	precision_to_print = format->precision - len;
	if (format->precision > num)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	i += ft_putnbr_i(num);
	return (i);
}

int		print_zero_pad_true_width(int number, char print, int w_to_print)
{
	int i;
	int num;

	i = 0;
	num = number;
	if (number < 0)
	{
		i += ft_putchar('-');
		num = -number;
	}
	i += print_x_time(print, w_to_print);
	i += ft_putnbr_i(num);
	return (i);
}
