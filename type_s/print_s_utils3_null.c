/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils3_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:14:14 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 16:56:44 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		redirect_no_justify_left(t_format *format, char print)
{
	int	max_precision;
	int i;

	i = 0;
	max_precision = format->precision;
	if (format->flags.precision == false && format->flags.width == false)
		i += ft_putstr("(null)");
	else if (format->flags.precision == false && format->flags.width == true)
		i += print_pad_null_s_no_left(format, max_precision);
	else if (format->flags.precision == false && format->flags.width == false)
		i += ft_putstr("(null)");
	else if (format->flags.precision == true && max_precision == 0)
		i += ft_put_pad_0_precision(format);
	else if (format->flags.precision == true && max_precision != 0)
		i += ft_putstr_limit("(null)", max_precision, format->width, print);
	return (i);
}

int		print_pad_null_s_no_left(t_format *spec, int max_precision)
{
	int		nb_pad;
	int		i;
	char	to_print;
	int		len_null;

	i = 0;
	len_null = 6;
	nb_pad = 0;
	to_print = c_padding_to_print(spec);
	if (spec->flags.precision == true)
		nb_pad = spec->width - max_precision;
	else if (spec->flags.width == true)
		nb_pad = (spec->width - len_null >= 0) ? spec->width - len_null : 0;
	if (nb_pad < 0)
		return (0);
	while (nb_pad)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	i += ft_putstr("(null)");
	return (i);
}

//pas utilisee finalement - a voir
int		width_precision_null_no_left(t_format *format)
{
	int len;
	int width_to_print;
	char to_print;
	int i;

	len = format->precision;
	width_to_print = format->width - len;
	i = 0;
	to_print = c_padding_to_print(format);
	i += print_x_time(to_print, width_to_print);
	i += ft_putstr_limit("(null)", format->precision, format->width, to_print);
	return (i);
}
