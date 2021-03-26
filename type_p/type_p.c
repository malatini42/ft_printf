/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:47:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 13:15:55 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		zero_pad_precision_p(t_format *f, unsigned long long p, char c, char *b)
{
	int i;
	int len;
	int	p_to_print;

	i = 0;
	len = (p == 0) ? 0 : count_nbr_u_base(p, b);
	p_to_print = f->precision - len;
	c = ' ';
	if ((unsigned int)f->precision >= p)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, p_to_print);
	if (p > 0)
	{
		i += ft_putstr("0x");
		ft_putnbr_p_base(p, b);
		i += count_p_length(p, b);
	}
	return (i);
}

int		width_precision_p_p(t_format *f, unsigned long long p, char c, char *b)
{
	int i;
	int w_to_print;
	int	p_to_print;

	p_to_print = (f->precision != 0 && p > 0) ?
		f->precision - count_nbr_u_base(p, b) : f->precision;
	if (f->precision > count_nbr_u_base(p, b) && p > 0)
		w_to_print = f->width - p_to_print - count_nbr_u_base(p, b);
	else
		w_to_print = f->width - count_p_length(p, b) - 2;
	i = 0;
	if (f->flags.zero_pad == true)
		c = ' ';
	if (f->width < f->precision)
		i += ft_putstr("0x");
	i += print_x_time(c, w_to_print);
	i += print_x_time('0', p_to_print);
	if (f->width >= f->precision)
		i += ft_putstr("0x");
	ft_putnbr_p_base(p, b);
	i += count_p_length(p, b);
	return (i);
}

int		pos_p_no_justify(t_format *f, unsigned long long p)
{
	int		i;
	int		len;
	int		w_to_print;
	char	c_to_print;
	char	*base;

	i = 0;
	len = 0;
	w_to_print = 0;
	base = "0123456789abcdef";
	c_to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == false)
	{
		i += ft_putstr("0x");
		ft_putnbr_p_base(p, base);
		i += count_p_length(p, base);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_p_p(f, p, c_to_print, base);
	else if (f->flags.precision == true && f->flags.width == false)
		i += zero_pad_precision_p(f, p, '0', base);
	else if (f->flags.precision == false && f->flags.width == true)
		i += zero_pad_width_p(f, p, c_to_print, base);
	return (i);
}

int		pos_p_justify(t_format *f, unsigned long long p, char *b)
{
	int		i;
	int		w_to_print;
	char	to_print;
	int		len;

	i = 0;
	to_print = c_padding_to_print(f);
	len = count_p_length(p, b);
	w_to_print = f->width > 0 ? f->width - len : -f->width - len;
	if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putstr("0x");
		ft_putnbr_p_base(p, b);
		i += count_p_length(p, b);
		i += print_x_time(to_print, w_to_print - 2);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_p(f, p, to_print, b);
	else if (f->precision == 0 && f->flags.width == false)
	{
		i += ft_putstr("0x");
		ft_putnbr_p_base(p, b);
		i += count_p_length(p, b);
	}
	return (i);
}

void	print_p(const char *str, t_format *f, va_list arg)
{
	unsigned long long	ptr;
	int					i;
	char				x;
	char				print;
	char				*base;

	i = 0;
	x = which_x_type(str);
	ptr = va_arg(arg, unsigned long long);
	base = "0123456789abcdef";
	print = c_padding_to_print(f);
	if (!ptr)
		i += handle_null_pointer(f, ptr);
	else
	{
		if (f->flags.justify_right == 0)
			i += pos_p_no_justify(f, ptr);
		else
			i += pos_p_justify(f, ptr, base);
	}
	f->printed_chars += i;
}
