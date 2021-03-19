/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:34 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 09:58:15 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_width_and_precision_neg(t_format *format, int number, char print)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = format->precision - n_size_i(-number);
	if (format->precision > n_size_i(-number))
		width_to_print = format->width - precision_to_print - n_size_i(number);//(number != 0) ? format->width - precision_to_print - n_size(-number) - 1
	else
		width_to_print = format->width - n_size_i(number);
	i = 0;
	if (format->flags.zero_pad == true)
		print = ' ';
	i += print_x_time(print, width_to_print);
	if (number != 0)
		i += ft_putchar('-');
	i += print_x_time('0', precision_to_print);
	ft_putnbr_i(-number);
	i += n_size_i(-number);
	return (i);
}

int		reverse_print_width_and_precision_neg(t_format *format, int number, char print)
{
	/*
	(void)format;
	(void)number;
	(void)print;
	*/
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = format->precision - n_size_i(-number);
	if (format->precision > n_size_i(-number))
		width_to_print = format->width - precision_to_print - n_size_i(number);//(number != 0) ? format->width - precision_to_print - n_size(-number) - 1
	else
		width_to_print = format->width - n_size_i(number);
	i = 0;
	if (number != 0)
		i += ft_putchar('-');
	i += print_x_time('0', precision_to_print);
	ft_putnbr_i(-number);
	i += n_size_i(-number);
	i += print_x_time(print, width_to_print);
	return (i);
}

int 	print_neg_no_justify(t_format *format, int number, char print)
{
	int 	i;
	int 	width_to_print;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	width_to_print = (format->width > n_size_i(number)) ? format->width - n_size_i(number) : 0;//a mettre dans la fonction d ensemble ?
	if (number == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (format->flags.precision == false && format->flags.width == true)
	{
		//revoir les differences ?
		if (format->flags.zero_pad == true)
			i += print_zero_pad_true_width(number, to_print, width_to_print);
		else
			i += print_zero_pad_then_number_width(format, number, to_print);
	}
	else if (format->flags.precision == false && format->flags.width == false)
		i += print_zero_pad_then_number_precision_i(format, number, to_print);
	else if (format->flags.precision == true && format->flags.width == false)
	{
		if (format->flags.precision == true && format->precision != 0)
			i += print_zero_pad_then_number_precision_i(format, number, print);
		else
		{
			return (i);
		}
	}
	else if (format->flags.precision == true && format->flags.width == true)
	{
		if (format->precision == 0 && number == 0)
		{
			i += print_x_time(to_print, format->width);
		}
		else
			i += print_width_and_precision_neg(format, number, to_print);
	}
	return (i);
}

int 	print_neg_justify(t_format *format, int number, char print)
{
	int		i;
	int		width_to_print;
	char	to_print;

	i = 0;
	width_to_print = (format->width > n_size_i(number)) ? format->width - n_size_i(number) : 0;
	to_print = c_padding_to_print(format);
	//Pas tres propre
	if (number == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (format->flags.precision == false && format->flags.width == true)
	{
		ft_putnbr_i(number);
		i += n_size_i(number);
		i += print_x_time(print, width_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == true)
	{
		if (format->precision == 0)
			i += print_x_time(to_print, format->width);
		else
			i += reverse_print_width_and_precision_neg(format, number, to_print);
	}
	else if (format->flags.precision == false && format->flags.precision == false && format->type == ID)//pb avec le type ?
	{
		ft_putnbr_i(number);
		i += n_size_i(number);
	}
	return (i);
}

int		print_neg_number(t_format *format, int number)
{
	int i;
	int len;
	//int width_to_print;
	int char_to_print;

	i = 0;
	len = 0;
	//width_to_print = 0;
	char_to_print = c_padding_to_print(format);
	if (format->flags.justify_left == false)
		i += print_neg_no_justify(format, number, char_to_print);
	else if (format->flags.justify_left == true)
		i += print_neg_justify(format, number, char_to_print);
	return (i);
}
