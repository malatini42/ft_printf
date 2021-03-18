/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:47:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 11:58:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		handle_null_pointer(t_format *format, unsigned long long pointer)
{
	int 	i;
	char 	to_print;
	int 	width;

	i = 0;
	(void)format;
	to_print = c_padding_to_print(format);
	width = (pointer != 0 || format->precision == 0) ?  format->width - 2 : format->width;//Cette condition est inutile voir fausse ?
	if (format->flags.justify_left == 0 && format->flags.precision == false && format->flags.width == true)
		i += print_x_time(to_print, format->width - 3);
	//A mettre dans une fonction separee
	//je ne gere pas tous les cas ?
	else if (format->flags.precision == true && format->precision == 0)
	{
		if (format->flags.width == true)//format->flags.justify_left == false - revoir conditions
			i += print_x_time(to_print, width);
		i += ft_putstr("0x");
		return (i);
	}
	i += ft_putstr("0x0");
	if (format->flags.precision == true && format->precision != 0)
	{
		i += print_x_time('0', format->precision - 1);
	}
	return (i);
}

int		print_zero_pad_then_number_precision_p(t_format * format, unsigned long long pointer, char print, char *base)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (pointer == 0) ? 0 : count_nbr_u_base(pointer, base);
	precision_to_print = format->precision - len;
	print = ' ';//A mettre en argument
	if ((unsigned int)format->precision >= pointer)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	if (pointer > 0)
		i += ft_putnbr_u_base(pointer, base);
	//i += number == 0 ? 0 : n_size_u(number);
	return (i);
}

int		print_width_and_precision_pos_p(t_format *format, unsigned long long pointer, char print, char *base)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = (pointer > 0) ? format->precision - count_nbr_u_base(pointer, base) : format->precision;
	if (format->precision > count_nbr_u_base(pointer, base) && pointer > 0)
		width_to_print = format->width - precision_to_print - count_nbr_u_base(pointer, base);//Si le resultat est positif
	/*
	else if (pointer == 0)
		width_to_print = format->width - precision_to_print;
	*/
	else
		width_to_print = format->width - count_nbr_u_base(pointer, base) - 2;
	i = 0;
	if (format->flags.zero_pad == true)
		print = ' ';
	if (format->width < format->precision)
		i += ft_putstr("0x");
	i += print_x_time(print, width_to_print);
	i += print_x_time('0', precision_to_print);//?
	/*if (pointer > 0)
	{*/
	if (format->width > format->precision)
		i += ft_putstr("0x");
	i += ft_putnbr_u_base(pointer, base);
	//}
	return (i);
}

int 	print_pos_p_no_justify(t_format *format, unsigned long long pointer)
{
	int 	i;
	int 	len;
	int 	width_to_print;
	char	char_to_print;
	char 	*base;

	i = 0;
	len = 0;
	width_to_print = 0;
	base =  "0123456789abcdef";
	char_to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
	{
		i += ft_putnbr_u_base(pointer, base);
	}
	else if (format->flags.precision == true && format->flags.width == true)
		i += print_width_and_precision_pos_p(format, pointer, char_to_print, base);
	else if (format->flags.precision == true && format->flags.width == false)
		i += print_zero_pad_then_number_precision_p(format, pointer, '0', base);
	/* revoir toutes les fonctions */
	/*
	else if (format->flags.precision == false && format->flags.width == true)
		i += print_zero_pad_then_number_width_p(format, number, char_to_print, base);

	*/
	return (i);
}

int		print_pos_p_number(t_format *format, unsigned long long pointer)
{
	int 	i;
	char 	print;

	i = 0;
	print = c_padding_to_print(format);
	if (format->flags.justify_left == 0)
		i += print_pos_p_no_justify(format, pointer);
	/*
	else
		i += print_pos_p_justify(format, number, x);
	*/
	return (i);
}


void	print_p(const char *str, t_format *format, va_list arg_ptr)
{
	unsigned long long	pointer;
	int 				i;
	char 				x;

	i = 0;
	x = which_x_type(str);
	pointer = va_arg(arg_ptr, unsigned long long);
	if (!pointer)
		i += handle_null_pointer(format, pointer);
	else
		i += print_pos_p_number(format, pointer);
	format->printed_chars += i;//verifier
}
