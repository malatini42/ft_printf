/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:56:14 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_then_number(t_format *f, int n)
{
	int		i;
	char	to_print;
	int		width_to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	width_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	i += print_x_time(to_print, width_to_print);
	i += ft_putnbr_i(n);
	return (i);
}

int		print_zero_pad_then_number_width(t_format *f, int n, char c)
{
	int i;
	int len;
	int w_to_print;
	int num;

	i = 0;
	num = n;
	if (n < 0 && f->flags.zero_pad == true)
	{
		ft_putchar('-');
		num = -n;
	}
	len = n_size_i(num);
	w_to_print = f->width - len;
	if ((int)f->width > -num && num < 0)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, w_to_print);
	i += ft_putnbr_i(num);
	if (f->flags.precision == false && f->flags.width == true 
		&& f->width < 0 && n > 0)
		i += print_x_time(c, -f->width -len);
	return (i);
}

int		print_zero_pad_then_number_precision_i(t_format *f, int n, char c)
{
	int i;
	int len;
	int p_to_print;
	int num;

	i = 0;
	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
		i++;
	}
	len = n_size_i(num);
	p_to_print = f->precision - len;
	if (f->precision > num)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, p_to_print);
	i += ft_putnbr_i(num);
	return (i);
}

int		print_zero_pad_true_width(int n, char c, int w_to_print)
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

void	print_id(t_format *f, va_list arg)
{
	int number;
	int i;

	i = 0;
	number = va_arg(arg, int);
	if (number > 0)
		i += print_pos_number(f, (unsigned int)number);
	else 
		i += print_neg_number(f, number);
	f->printed_chars += i;
}