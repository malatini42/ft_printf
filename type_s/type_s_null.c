/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:06:11 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 13:47:29 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		null_s_width_no_justify(t_format *f, int preci)
{
	int	nb_pad;
	int	i;

	i = 0;
	nb_pad = 0;
	if (f->flags.precision == true)
		nb_pad = f->width - preci;
	else if (f->flags.width == true)
		nb_pad = (f->width - 6 >= 0) ? f->width - 6 : 0;
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

int		null_s_no_justify(t_format *f)
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
		i += ft_putstr_limit("(null)", f->precision, f->width, f);
	else if (f->flags.precision == true && f->width == false)
		i += ft_putstr("(null)");
	return (i);
}

int		width_precision_null_left(t_format *f)
{
	int		len;
	int		w_to_print;
	int		i;
	char	*n;
	int		a_width;

	len = f->precision >= 0 ? f->precision : 6;
	a_width = f->width > 0 ? f->width : -f->width;
	w_to_print = len < 6 ? a_width - len : a_width - 6;
	i = 0;
	n = ft_strdup("(null)");
	while (i < len && i < 6)
	{
		ft_putchar(n[i]);
		i++;
	}
	i += print_x_time(c_padding_to_print(f), w_to_print);
	free(n);
	return (i);
}

int		null_s_justify(t_format *f)
{
	int	i;
	int	nb_pad;

	i = 0;
	nb_pad = 0;
	if (f->width < 6 && f->flags.precision == false)
		i += ft_putstr("(null)");
	if (f->flags.precision == true && f->flags.width == true)
		i += width_precision_null_left(f);
	else if (f->width >= 6 && f->flags.precision == false)
	{
		i += ft_putstr("(null)");
		i += print_x_time(c_padding_to_print(f), f->width - 6);
	}
	else if (f->flags.precision == true && f->flags.width == false
		&& f->precision != 0)
		i += ft_putstr_limit("(null)", f->precision, 0, f);
	else if (f->flags.precision == true && f->flags.width == true
		&& f->width < 0 && f->precision == 0)
		i += print_x_time(c_padding_to_print(f), -f->width);
	else if (f->flags.precision == true && f->flags.width == true
		&& f->width < 0 && f->precision < 0)
		i += ft_putstr("(null)");
	return (i);
}
