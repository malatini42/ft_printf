/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id_neg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:59:50 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 11:36:19 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		calculate_width(t_format *f, int n, int p_to_print)
{
	int w_to_print;

	if (f->precision > n_size_u(-n))
		w_to_print = f->width - p_to_print - n_size_i(n);
	else
		w_to_print = f->width - n_size_i(n);
	if (f->precision < 0 && f->width > 0 && n == 0)
		w_to_print = f->width - n_size_i(n);
	return (w_to_print);
}

int		calculate_width_neg(t_format *f, int n)
{
	int	w_to_print;

	if (f->width < n_size_i(n))
		w_to_print = -(f->width) - n_size_i(n);
	if (f->width > 0)
		w_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	return (w_to_print);
}

int		width_precision_neg_no_justify(t_format *f, int n, char c)
{
	int i;

	i = 0;
	if (n == INT_MIN && f->width > n_size_u(INT_MIN))
	{
		i += print_x_time(' ', f->width - n_size_u(INT_MIN) - 1);
		return (i += ft_putstr("-2147483648"));
	}
	if (f->precision == 0 && n == 0)
		i += print_x_time(' ', f->width);
	else
		i += width_precision_neg(f, n, c);
	return (i);
}

int		precision_neg_justify(t_format *f, int n)
{
	int		i;
	char	c;

	i = 0;
	c = c_padding_to_print(f);
	if (f->precision == 0)
	{
		if (f->width < 0 && n == 0)
			i += print_x_time(c, -f->width);
		else if (n != 0)
		{
			i += ft_putnbr_i(n);
			if (f->width > n_size_i(n))
				i += print_x_time(c, f->width - n_size_i(n));
			else if (f->width < 0)
				i += print_x_time(c, (-f->width - n_size_i(n)));
		}
		else if (n == 0 && f->width > n)
			i += print_x_time(c, f->width);
	}
	else
		i += r_print_width_precision_neg(f, n, c_padding_to_print(f));
	return (i);
}

int		precision_neg_justify_specials(t_format *f, int n, int p_to_print)
{
	int i;

	i = 0;
	if (f->precision >= n_size_i(n) && n != 0 && f->precision > 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (f->precision > 0)
		i += print_x_time('0', p_to_print - n_size_i(n));
	i += ft_putnbr_i(n);
	return (i);
}
