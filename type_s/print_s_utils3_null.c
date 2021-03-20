/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils3_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:14:14 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:30:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		null_s_width_no_justify(t_format *f, int max_precision)
{
	int		nb_pad;
	int		i;
	int		l_null;

	i = 0;
	l_null = 6;
	nb_pad = 0;
	if (f->flags.precision == true)
		nb_pad = f->width - max_precision;
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

int		null_s_no_justify(t_format *f, char print)
{
	int	max_precision;
	int i;

	i = 0;
	max_precision = f->precision;
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putstr("(null)");
	else if (f->flags.precision == false && f->flags.width == true)
		i += null_s_width_no_justify(f, max_precision);
	else if (f->flags.precision == false && f->flags.width == false)
		i += ft_putstr("(null)");
	else if (f->flags.precision == true && max_precision == 0)
		i += ft_put_pad_0_precision(f);
	else if (f->flags.precision == true && max_precision != 0)
		i += ft_putstr_limit("(null)", max_precision, f->width, print);
	return (i);
}
