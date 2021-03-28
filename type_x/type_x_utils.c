/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:42:22 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 17:02:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		calculate_w_p(t_format *f, int pre, unsigned int n, char *b)
{
	int	w;
	int	len;

	len = count_nbr_u_base(n, b);
	if (f->precision > len && n > 0)
		w = f->width - pre - len;
	else if (n == 0)
		w = f->width - pre;
	else
		w = f->width - len;
	return (w);
}

int		calculate_r_width_p_x(t_format *f, int len, int p, unsigned int n)
{
	int	w;

	p = p < 0 ? 0 : p;
	if (f->precision > len && n > 0)
		w = f->width > 0 ? f->width - p - len : -f->width - p - len;
	else if (n == 0)
		w = f->width > 0 ? f->width - p : -f->width - p;
	else
		w = f->width > 0 ? f->width - len : -f->width - len;
	return (w);
}

int		r_width_precision_pos_x(t_format *f, unsigned int n, char c, char *b)
{
	int i;
	int w;
	int p;

	i = 0;
	p = (n > 0) ? f->precision - count_p_length(n, b) : f->precision;
	w = calculate_r_width_p_x(f, count_p_length(n, b), p, n);
	if (!(f->precision <= -1 && f->width <= -1))
	{
		if (n_size_u(n) < 10)
			i += print_x_time('0', p);
		i = handle_special_maxs(f, n, i);
		if (n != 0)
			i += ft_putnbr_u_base(f, n, b);
		else if (n == 0 && f->precision < 0)
		{
			i += ft_putnbr_i(0);
			return (i += print_x_time(c_padding_to_print(f), f->width - 1));
		}
		i += print_x_time(c, w);
	}
	else
		i += handle_negs_ux(f, n, b, w);
	return (i);
}

int		zero_pad_width_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int len;

	i = 0;
	len = count_nbr_u_base(n, b);
	i += print_x_time(p, f->width - len);
	i += ft_putnbr_u_base(f, n, b);
	return (i);
}

int		handle_null_pointer(t_format *f, unsigned long long p)
{
	int		i;
	int		w;
	int		len;

	i = 0;
	len = count_p_length(p, "0123456789abcdef");
	w = f->width > 0 ? f->width - len - 1 : -f->width - len - 1;
	if (f->flags.justify_right == 0 && f->flags.precision == false &&
			f->flags.width == true)
		i += print_x_time(c_padding_to_print(f), f->width - 3);
	else if (f->flags.precision == true && f->precision == 0)
	{
		if (f->flags.width == true && f->flags.justify_right == false)
			i += print_x_time(c_padding_to_print(f), w);
		i += ft_putstr("0x");
		if (f->flags.width == true && f->flags.justify_right == true)
			i += print_x_time(c_padding_to_print(f), w);
		return (i);
	}
	i += ft_putstr("0x0");
	if (f->flags.precision == true && f->precision != 0)
		i += print_x_time('0', f->precision - 1);
	if (f->flags.width == true && f->flags.justify_right == true)
		i += print_x_time(c_padding_to_print(f), w - 1);
	return (i);
}
