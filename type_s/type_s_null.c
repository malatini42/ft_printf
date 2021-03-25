/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:06:11 by malatini          #+#    #+#             */
/*   Updated: 2021/03/25 17:00:31 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		null_s_width_no_justify(t_format *f, int preci)
{
	int		nb_pad;
	int		i;
	int		l_null;

	i = 0;
	l_null = 6;
	nb_pad = 0;
	if (f->flags.precision == true)
		nb_pad = f->width - preci;
	else if (f->flags.width == true)
		nb_pad = (f->width - l_null >= 0) ? f->width - l_null : 0;
	if (nb_pad < 0)
		return (0);
	while (nb_pad)
	{
		ft_putchar(c_padding_to_print(f));
		i++;
		nb_pad--;
	}
	i += ft_putstr("(null)");
	return (i);
}

int		null_s_no_justify(t_format *f, char c)
{
	int i;

	i = 0;
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putstr("(null)");
	else if (f->flags.precision == false && f->flags.width == true)
		i += null_s_width_no_justify(f, f->precision);
	else if (f->flags.precision == false && f->flags.width == false)
		i += ft_putstr("(null)");
	else if (f->flags.precision == true && f->precision == 0)
		i += ft_put_pad_0_precision(f);
	else if (f->flags.precision == true && f->precision != 0)
		i += ft_putstr_limit("(null)", f->precision, f->width, c, f);
	return (i);
}

int		width_precision_null_left(t_format *f)
{
	int		len;
	int		w_to_print;
	char	to_print;
	int		i;
	char	*n;

	len = f->precision;
	w_to_print = len < 6 ? f->width - len : f->width - 6;
	i = 0;
	n = ft_strdup("(null)");
	to_print = c_padding_to_print(f);
	while (i < 6 && i < f->precision)
	{
		ft_putchar(n[i]);
		i++;
	}
	i += print_x_time(to_print, w_to_print);
	free(n);
	return (i);
}

int		null_s_justify(t_format *f)
{
	int		i;
	int		nb_pad;
	char	to_print;
	int		len_null;

	i = 0;
	len_null = 6;
	nb_pad = 0;
	to_print = c_padding_to_print(f);
	if (f->width < len_null && f->flags.precision == false)
		i += ft_putstr("(null)");
	else if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_null_left(f);
	else if (f->flags.precision == true && f->flags.width == false)
		i += print_x_time(to_print, f->width);
	else if (f->width > len_null && f->flags.precision == false)
	{
		i += ft_putstr("(null)");
		i += print_x_time(to_print, f->width - len_null);
	}
	return (i);
}
