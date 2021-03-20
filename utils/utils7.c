/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:06:31 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:15:59 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		zero_pad_width(t_format *format, int number, char print)
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

int		r_width_precision_u(t_format *f, int n, char print)
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
	i += print_x_time('0', p_to_print);
	if (n > 0)
	{
		ft_putnbr_u(n);//changer le retour de celle-ci pour ne faire qu une ligne
		i += n_size_u(n);
	}
	i += print_x_time(print, w_to_print);
	return (i);
}

int		zero_pad_precision_u(t_format * f, unsigned int n, char print)
{
	int i;
	int len;
	int p_to_print;

	i = 0;
	len = (n == 0) ? 0 : n_size_u(n);
	p_to_print = f->precision - len;
	if ((unsigned int)f->precision >= n)
	{
		f->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, p_to_print);
	if (n > 0)
		ft_putnbr_u(n);
	i += n == 0 ? 0 : n_size_u(n);
	return (i);
}
