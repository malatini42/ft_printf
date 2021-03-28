/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:23:14 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 12:25:58 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_precision_u(t_format *f, unsigned int n)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (n > 0) ? f->precision - n_size_u(n) : f->precision;
	w_to_print = calculate_width_u(f, n, p_to_print);
	i = 0;
	if (f->width <= 0 && f->flags.width == true && f->precision < 0)
		return (i += ft_putnbr_u(n));
	else if (f->width > 0 && f->precision < 0 && n == 0)
	{
		i += print_x_time(c_padding_to_print(f), f->width - n_size_i(n));
		return (i += ft_putnbr_i(0));
	}
	if (!(f->width > 0 && f->precision < 0))
		i += print_x_time(' ', w_to_print);
	i += print_x_time('0', p_to_print);
	if (n != 0)
	{
		if (f->width > 0 && f->precision < 0)
			i += print_x_time(c_padding_to_print(f), f->width - n_size_u(n));
		i += ft_putnbr_u(n);
	}
	return (i);
}

int		u_no_justify(t_format *f, unsigned int n)
{
	int i;

	i = 0;
	if (f->flags.precision == false && f->flags.width == false)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);
	}
	else if (f->flags.precision == false && f->flags.width == true)
		i += zero_pad_width(f, n, c_padding_to_print(f));
	else if (f->flags.precision == true && f->flags.width == false)
		i += zero_pad_precision_u(f, n, c_padding_to_print(f));
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_u(f, n);
	return (i);
}

int		u_justify(t_format *f, unsigned int n, char c)
{
	int	i;
	int	w_to_print;

	i = 0;
	w_to_print = (f->width > n_size_u(n)) ? f->width - n_size_u(n) : 0;
	if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putnbr_u(n);
		if (f->width > 0)
			i += print_x_time(c, w_to_print);
		else
			i += print_x_time(c, -f->width - n_size_u(n));
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_u(f, n, c_padding_to_print(f));
	else if (f->flags.precision == false && f->flags.width == false)
		i += ft_putnbr_u(n);
	else if (f->flags.precision == true && f->flags.width == false
		&& (f->precision != 0 || n != 0))
	{
		if (f->precision > n_size_u(n))
			i += print_x_time('0', f->precision - n_size_u(n));
		i += ft_putnbr_u(n);
	}
	return (i);
}

int		u_number(t_format *f, unsigned int n)
{
	int		i;
	char	print;

	i = 0;
	print = c_padding_to_print(f);
	if (f->flags.justify_right == 0)
		i += u_no_justify(f, n);
	else
		i += u_justify(f, n, print);
	return (i);
}

void	print_u(t_format *f, va_list arg)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(arg, unsigned int);
	i += u_number(f, n);
	f->printed_chars += i;
}
