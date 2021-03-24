/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/24 14:57:05 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_precision_pos_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (n > 0) ? f->precision - count_nbr_u_base(n, b) : f->precision;
	if (f->precision > count_nbr_u_base(n, b) && n > 0)
		w_to_print = f->width - p_to_print - count_nbr_u_base(n, b);
	else if (n == 0)
		w_to_print = f->width - p_to_print;
	else
		w_to_print = f->width - count_nbr_u_base(n, b);
	i = 0;
	//write(1, "coucou\n", 6);
	if (n == 0 && f->precision < 0 && f->width == 0 && f->flags.width == true)
	{
		i += ft_putchar('0');
		return (i);
	}
	/*
	if (f->width == 0 && f->flags.width == true
		&& f->flags.precision == true && f->type == U)
	{
		//a continuer
		//write(1, "coucou", 6);
		ft_putnbr_u(n);
		i += n_size_u(n);
		return (i);
	}
	*/
	if (f->flags.zero_pad == true)
		p = ' ';
	i += print_x_time(p, w_to_print);
	i += print_x_time('0', p_to_print);
	if (n > 0)
		i += ft_putnbr_u_base(n, b);
	return (i);
}

int		zero_pad_precision_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (n == 0) ? 0 : count_nbr_u_base(n, b);
	precision_to_print = f->precision - len;
	if ((unsigned int)f->precision >= n)
	{
		f->flags.zero_pad = true;
		p = '0';
	}
	i += print_x_time(p, precision_to_print);
	if (n != 0)
		i += ft_putnbr_u_base(n, b);
	if (n == 0 && f->precision < 0 && f->flags.width == false)
	{
		//write(1, "coucou", 6);
		i += ft_putnbr_i(0);
	}
	return (i);
}

int		pos_x_justify(t_format *f, unsigned int n, char x)
{
	int		i;
	int		w_to_print;
	char	to_print;
	char	*base;

	i = 0;
	to_print = c_padding_to_print(f);
	base = (x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	w_to_print = (f->width > count_nbr_u_base(n, base)) ?
		f->width - count_nbr_u_base(n, base) : 0;
	if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putnbr_u_base(n, base);
		i += print_x_time(to_print, w_to_print);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_pos_x(f, n, to_print, base);
	return (i);
}

int		pos_x_no_justify(t_format *f, unsigned int n, char x)
{
	int		i;
	char	c_to_print;
	char	*base;

	i = 0;
	base = (x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	c_to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putnbr_u_base(n, base);
	else if (f->flags.precision == false && f->flags.width == true)
		i += zero_pad_width_x(f, n, c_to_print, base);
	else if (f->flags.precision == true && f->flags.width == false)
		i += zero_pad_precision_x(f, n, '0', base);
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_pos_x(f, n, c_to_print, base);
	return (i);
}

void	print_x(const char *str, t_format *f, va_list arg)
{
	int		i;
	char	print;
	int		n;

	i = 0;
	n = va_arg(arg, unsigned int);
	print = c_padding_to_print(f);
	if (f->flags.justify_right == 0)
		i += pos_x_no_justify(f, n, which_x_type(str));
	else
		i += pos_x_justify(f, n, which_x_type(str));
	f->printed_chars += i;
}
