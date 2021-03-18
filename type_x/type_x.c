/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 13:31:53 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int 	print_pos_x_justify(t_format *format, unsigned int number, char x)
{
	int 	i;
	int		width_to_print;
	char	to_print;
	char 	*base;

	i = 0;
	to_print = c_padding_to_print(format);
	base = (x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	width_to_print = (format->width > count_nbr_u_base(number, base)) ? format->width - count_nbr_u_base(number, base) : 0;
	if (format->flags.precision == false && format->flags.width == true)
	{
		i += ft_putnbr_u_base(number, base);
		i += print_x_time(to_print, width_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == true)
		i += reverse_print_width_and_precision_pos_x(format, number, to_print, base);
	return (i);
}

int 	print_pos_x_no_justify(t_format *format, unsigned int number, char x)
{
	int 	i;
	int 	len;
	int 	width_to_print;
	char	char_to_print;
	char 	*base;

	i = 0;
	len = 0;
	width_to_print = 0;
	base = (x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	char_to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
		i += ft_putnbr_u_base(number, base);
	/* revoir toutes les fonctions */
	else if (format->flags.precision == false && format->flags.width == true)
		i += print_zero_pad_then_number_width_x(format, number, char_to_print, base);
	else if (format->flags.precision == true && format->flags.width == false)
		i += print_zero_pad_then_number_precision_x(format, number, '0', base);
	else if (format->flags.precision == true && format->flags.width == true)
		i += print_width_and_precision_pos_x(format, number, char_to_print, base);
	return (i);
}

int		print_pos_x_number(t_format *format, unsigned int number, char x)
{
	int 	i;
	char 	print;

	i = 0;
	print = c_padding_to_print(format);
	if (format->flags.justify_left == 0)
		i += print_pos_x_no_justify(format, number, x);
	else
		i += print_pos_x_justify(format, number, x);
	return (i);
}

void	print_x(const char *str, t_format *format, va_list arg_ptr)
{
	unsigned int	number;
	int 			i;
	char 			x;

	i = 0;
	x = which_x_type(str);
	number = va_arg(arg_ptr, unsigned int);
	i += print_pos_x_number(format, number, x);
	format->printed_chars += i;
}
