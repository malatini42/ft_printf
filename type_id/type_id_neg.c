/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:34 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 11:31:39 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		neg_width(t_format *f, int n, int i, char c)
{
	if (f->flags.zero_pad == true)
	{
		if (f->width <= 0)
		{
			i += ft_putnbr_i(n);
			i += print_x_time(' ', -f->width - n_size_i(n));
		}
		else if (f->width > 0)
		{
			if (n != 0)
				i += ft_putchar('-');
			i += print_x_time('0', f->width - n_size_i(n));
			i += ft_putnbr_i(-n);
		}
	}
	else if (f->flags.precision == false && f->width < 0)
	{
		ft_putnbr_i(n);
		i += print_x_time(c, -f->width - n_size_i(n));
	}
	else
		i += zero_pad_width(f, n, c_padding_to_print(f));
	return (i);
}

int		width_precision_neg(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = f->precision - n_size_i(-n);
	w_to_print = calculate_width(f, n, p_to_print);
	if (f->precision < 0 && f->width < 0)
		w_to_print = -f->width;
	i = 0;
	if (f->flags.zero_pad == true && f->precision > n)
		c = ' ';
	if (f->width > 0 && !(f->flags.zero_pad == true && f->precision < 0
		&& f->width > n_size_i(n) && n != 0))
		i += print_x_time(c, w_to_print);
	if (n != 0)
		i += ft_putchar('-');
	if (f->flags.zero_pad == true && f->precision < 0
		&& f->width > n_size_i(n) && n != 0)
		i += print_x_time('0', w_to_print);
	i += print_x_time('0', p_to_print);
	i += ft_putnbr_i(-n);
	return (i);
}

int		r_print_width_precision_neg(t_format *f, int n, char p)
{
	int i;
	int w_to_print;
	int p_to_print;
	int a_width;

	p_to_print = f->precision - n_size_i(-n);
	a_width = f->width > 0 ? f->width : -f->width;
	i = 0;
	if (f->precision > n_size_i(-n))
		w_to_print = a_width - p_to_print - n_size_i(n);
	else
		w_to_print = a_width - n_size_i(n);
	if (f->precision < 0)
	{
		f->flags.precision = false;
		if (f->width < 0)
			w_to_print = -f->width - n_size_i(n);
	}
	if (n != 0)
		i += ft_putchar('-');
	i += print_x_time('0', p_to_print);
	i += ft_putnbr_i(-n);
	i += print_x_time(p, w_to_print);
	return (i);
}

int		neg_no_justify(t_format *f, int n, char c)
{
	int	i;
	int	w_to_print;

	i = 0;
	w_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	if (n == INT_MIN && f->width < n_size_u(INT_MIN))
		i += ft_putstr("-2147483648");
	else if (f->flags.precision == false && f->flags.width == true)
		i += neg_width(f, n, i, c);
	else if (f->flags.precision == false && f->flags.width == false)
		i += zero_pad_precision_i(f, n, c);
	else if (f->flags.precision == true && f->flags.width == false)
	{
		if (f->precision != 0)
			i += zero_pad_precision_i(f, n, c);
		else if (f->precision == 0 && n != 0)
			i += ft_putnbr_i(n);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_neg_no_justify(f, n, c);
	return (i);
}

int		neg_justify(t_format *f, int n, char c)
{
	int	i;
	int	w_to_print;
	int p_to_print;

	i = 0;
	p_to_print = f->precision > 0 ? f->precision : -f->precision;
	w_to_print = calculate_width_neg(f, n);
	if (n == -2147483648)
		i += ft_putstr("-2147483648");
	else if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putnbr_i(n);
		i += print_x_time(c, w_to_print);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += precision_neg_justify(f, n);
	else if (f->flags.precision == true && f->flags.width == false
		&& (n != 0 || f->precision > 0))
		i += precision_neg_justify_specials(f, n, p_to_print);
	else if (f->flags.precision == false && f->flags.width == false)
		i += ft_putnbr_i(n);
	else if (f->flags.precision == true && f->flags.width == false && n == 0)
		if (f->precision < 0)
			i += ft_putchar('0');
	return (i);
}
