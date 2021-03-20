/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:06:31 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:10:08 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr_limit(const char *s, int precision, int w, char c)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	if (w > 0)
		len += print_x_time(c, w - precision);
	if (precision > 0)
	{
		while (i < precision && i < 6)
		{
			if (i >= precision)
				return (i);
			ft_putchar(s[i]);
			i++;
		}
	}
	else
		i = ft_putstr("(null)");
	return (i + len);
}

int		ft_put_pad_0_precision(t_format *f)
{
	char	to_print;
	int		width;

	width = f->width;
	to_print = c_padding_to_print(f);
	while (width > 0)
	{
		ft_putchar(to_print);
		width--;
	}
	return (f->width);
}

int		zero_pad_width(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int num;

	i = 0;
	num = n;
	if (n < 0 && f->flags.zero_pad == true)
	{
		ft_putchar('-');
		num = -n;
	}
	w_to_print = f->width - n_size_i(num);
	if ((int)f->width > -num && num < 0)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, w_to_print);
	i += ft_putnbr_i(num);
	if (f->flags.precision == false && f->flags.width == true
		&& f->width < 0 && n > 0)
		i += print_x_time(c, -f->width - n_size_i(num));
	return (i);
}

int		r_width_precision_u(t_format *f, int n, char c)
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
		ft_putnbr_u(n);
		i += n_size_u(n);
	}
	i += print_x_time(c, w_to_print);
	return (i);
}

int		zero_pad_precision_u(t_format *f, unsigned int n, char print)
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
