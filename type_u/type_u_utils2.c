/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:54:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 14:38:45 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//pas utilisee encore
/*
int		handle_true_width(t_format *f, int n, int w_to_print, int i)
{
	char	c;

	c = c_padding_to_print(f);
	if (f->width <= 0 && f->flags.width == true && f->precision < 0)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);
		return (i);
	}
	else if (f->width > 0 && f->precision < 0 && f->flags.precision == true
		&& n == 0)
	{
		i += print_x_time(c_padding_to_print(f), f->width - n_size_i(n));
		i += ft_putnbr_i(0);
		return (i);
	}
	if (!(f->width > 0 && f->precision < 0))
		i += print_x_time(c, w_to_print);
	return (i);
}
*/

int		calculate_width_u(t_format *f, unsigned int n, int p_to_print)
{
	int w_to_print;

	if (f->precision > n_size_u(n) && n > 0)
		w_to_print = f->width - p_to_print - n_size_u(n);
	else if (n == 0)
		w_to_print = f->width - p_to_print;
	else
		w_to_print = f->width - n_size_u(n);
	return (w_to_print);
}

int		calculate_w_u_r(t_format *f, unsigned int n, int s, int p)
{
	int	w;

	if (f->precision > s && n > 0)
		w = f->width > 0 ? f->width - p - s : -f->width - p - s;
	else if (n == 0)
		w = f->width > 0 ? f->width - p : - f->width - p;
	else
		w = f->width > 0 ? f->width - s : -f->width - s;
	return (w);
}

int		handle_neg_w_p_u(t_format *f, unsigned int n, int s, int i)
{
	i += ft_putnbr_u(n);
	i += print_x_time(c_padding_to_print(f), - f->width - s);
	return (i);
}