/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 18:07:12 by malatini         ###   ########.fr       */
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

int		print_zero_pad_then_number_width(t_format *format, int number, char print)
{
	int i;
	int len;
	int width_to_print;
	int num;

	i = 0;
	num = number;
	if (number < 0 && format->flags.zero_pad == true)
	{
		ft_putchar('-');
		num = -number;
	}
	len = n_size_i(num);
	width_to_print = format->width - len;
	if ((int)format->width > -num && num < 0)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, width_to_print);
	i += ft_putnbr_i(num);
	if (format->flags.precision == false && format->flags.width == true && format->width < 0 && number > 0)
		i += print_x_time(print, -format->width -len);
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

void	print_id(t_format *format, va_list arg_ptr)
{
	int number;
	int i;

	i = 0;
	number = va_arg(arg_ptr, int);
	if (number > 0)
		i += print_pos_number(format, (unsigned int)number);
	else 
		i += print_neg_number(format, number);
	format->printed_chars += i;
	
}