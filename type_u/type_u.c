/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:23:14 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:14:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_precision_u(t_format *f, unsigned int n, char print)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (n > 0) ? f->precision - n_size_u(n) : f->precision;
	if (f->precision > n_size_u(n) && n > 0)
		w_to_print = f->width - p_to_print - n_size_u(n);
	else if (n == 0)
		w_to_print = f->width - p_to_print;
	else
		w_to_print = f->width - n_size_u(n);
	i = 0;
	if (f->flags.zero_pad == true)
		print = ' ';
	i += print_x_time(print, w_to_print);
	i += print_x_time('0', p_to_print);
	if (n > 0)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);
	}
	return (i);
}
int 	u_no_justify(t_format *f, unsigned int n)
{
	int i;

	i = 0;
	if (f->flags.precision == false && f->flags.width == false)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);//a mettre ensemble
	}
	else if (f->flags.precision == false && f->flags.width == true)
		i += zero_pad_width(f, n, c_padding_to_print(f));
	else if (f->flags.precision == true && f->flags.width == false)
		i += zero_pad_precision_u(f, n, c_padding_to_print(f));
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_u(f, n, c_padding_to_print(f));
	return (i);
}

int 	u_justify(t_format *f, unsigned int n, char print)
{
	int 	i;
	int		w_to_print;

	i = 0;
	w_to_print = (f->width > n_size_u(n)) ? f->width - n_size_u(n) : 0;
	if (f->flags.precision == false && f->flags.width == true)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);//A mettre ensemble
		i += print_x_time(print, w_to_print);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_u(f, n, c_padding_to_print(f));
	return (i);
}

int		u_number(t_format *format, unsigned int number)
{
	int 	i;
	char 	print;

	i = 0;
	print = c_padding_to_print(format);
	if (format->flags.justify_right == 0)
		i += u_no_justify(format, number);
	else
		i += u_justify(format, number, print);
	return (i);
}

void	print_u(t_format *format, va_list arg_ptr)
{
	unsigned int number;
	int i;

	i = 0;
	number = va_arg(arg_ptr, unsigned int);
	i += u_number(format, number);
	format->printed_chars += i;
}
