/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:32 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 11:41:16 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_precision_pos(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int p_to_print;

	i = 0;
	p_to_print = f->precision - n_size_i(n);
	w_to_print = (f->precision > n_size_i(n) && f->precision > 0) ?
		f->width - p_to_print - n_size_i(n) : f->width - n_size_i(n);
	if (f->precision <= 0 && f->width > 0)
	{
		w_to_print = n == 0 ? f->width : f->width - n_size_i(n);
		p_to_print = 0;
	}
	if (f->flags.zero_pad == true)
		c = ' ';
	if (f->width > n_size_i(n) && f->precision >= 0)
		i += print_x_time(c, w_to_print);
	else if (f->flags.zero_pad == true && f->precision <= n_size_i(n))
		i += print_x_time('0', w_to_print);
	else if ((f->flags.zero_pad == false) ||
		(n < 10 && n > 0 && f->flags.zero_pad == true))
		i += print_x_time(' ', w_to_print);
	i += print_x_time('0', p_to_print);
	i += ft_putnbr_i(n);
	return (i);
}

int		r_width_precision_pos(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int p_to_print;
	int a_width;

	p_to_print = f->precision > 0 ? f->precision - n_size_i(n) :
		f->precision - n_size_i(n);
	a_width = f->width > 0 ? f->width : -f->width;
	if (f->precision > n_size_i(n))
		w_to_print = a_width - p_to_print - n_size_i(n);
	else
		w_to_print = a_width - n_size_i(n);
	if (f->precision <= 0)
	{
		p_to_print = 0;
		if (f->width <= 0)
			w_to_print = -f->width - n_size_i(n);
	}
	if (f->precision > 0 && f->width < 0 && n < 10)
		w_to_print = -f->width - f->precision;
	i = 0;
	i += print_x_time('0', p_to_print);
	i += ft_putnbr_i(n);
	i += print_x_time(c, w_to_print);
	return (i);
}

int		pos_no_justify(t_format *f, int n)
{
	int i;
	int c_to_print;

	i = 0;
	c_to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putnbr_i(n);
	else if (f->flags.precision == false && f->flags.width == true)
		i += zero_pad_width(f, n, c_to_print);
	else if (f->flags.precision == true && f->flags.width == false)
		i += zero_pad_precision_i(f, n, c_to_print);
	else if (f->flags.precision == false && f->flags.width == true)
	{
		f->flags.zero_pad = true;
		i += zero_pad_width(f, n, c_to_print);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_pos(f, n, c_to_print);
	return (i);
}

int		pos_justify(t_format *f, int n, char c)
{
	int		i;
	int		w_to_print;
	int		p_to_print;

	i = 0;
	p_to_print = f->precision > 0 ? f->precision - n_size_i(n) : 0;
	if (f->width < n_size_i(n))
		w_to_print = -(f->width) - n_size_i(n);
	if (f->width > 0)
		w_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putnbr_i(n);
		i += print_x_time(c, w_to_print);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_pos(f, n, c_padding_to_print(f));
	else if (f->flags.precision == false && f->flags.width == false)
		i += ft_putnbr_i(n);
	else if (f->flags.precision == true && f->flags.width == false)
	{
		i += print_x_time('0', p_to_print);
		i += ft_putnbr_i(n);
	}
	return (i);
}

int		pos_number(t_format *f, int n)
{
	int	i;

	i = 0;
	if (f->flags.justify_right == 0)
		i += pos_no_justify(f, n);
	else
		i += pos_justify(f, n, c_padding_to_print(f));
	return (i);
}
