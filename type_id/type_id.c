/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 12:41:11 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_then_number(t_format *f, int n)
{
	int		i;
	char	to_print;
	int		w_to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	w_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	i += print_x_time(to_print, w_to_print);
	i += ft_putnbr_i(n);
	return (i);
}

int		zero_pad_precision_i(t_format *f, int n, char c)
{
	int i;
	int p_to_print;
	int num;

	i = 0;
	num = n;
	p_to_print = 0;
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
		i++;
	}
	if (f->precision > 0)
		p_to_print = f->precision - n_size_i(num);
	if (f->precision > n_size_i(num))
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c_padding_to_print(f), p_to_print);
	i += ft_putnbr_i(num);
	return (i);
}

int		zero_pad_true_width(int n, char c, int w_to_print)
{
	int i;
	int num;

	i = 0;
	num = n;
	if (n < 0)
	{
		i += ft_putchar('-');
		num = -n;
	}
	i += print_x_time(c, w_to_print);
	i += ft_putnbr_i(num);
	return (i);
}

int		zero_pad_width(t_format *f, unsigned int n, char c)
{
	int	i;
	int	w;

	i = 0;
	if (n < 0 && f->flags.zero_pad == true)
	{
		ft_putchar('-');
		n = -n;
	}
	w = f->width > 0 ? f->width - n_size_i(n) : -f->width - n_size_i(n);
	if ((unsigned int)f->width > -n && n < 0)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	if (f->width <= n_size_u(n) && f->flags.width == true && f->type == U)
		return (i += ft_putnbr_u(n));
	i += f->width >= 21 ? print_x_time(c, w - n_size_i(n)) : print_x_time(c, w);
	if (n == 2147483648)
		return (i += ft_putnbr_u(n));
	i += f->width > 10 ? ft_putnbr_u(n) : ft_putnbr_i(n);
	if (f->flags.precision == false && f->flags.width == true
		&& f->width < 0 && n > 0)
		i += print_x_time(c, -f->width - n_size_i(n));
	return (i);
}

void	print_id(t_format *f, va_list arg)
{
	int n;
	int i;

	i = 0;
	n = va_arg(arg, int);
	if (n > 0)
		i += pos_number(f, (unsigned int)n);
	else
	{
		if (f->flags.justify_right == false)
			i += neg_no_justify(f, n, c_padding_to_print(f));
		else if (f->flags.justify_right == true)
			i += neg_justify(f, n, c_padding_to_print(f));
	}
	f->printed_chars += i;
}
