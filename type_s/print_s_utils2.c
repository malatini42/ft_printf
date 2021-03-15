/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:12:09 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 17:38:14 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr_limit(const char *str, int precision, int width, char print)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	if (width > 0)
		len += print_x_time(print, width - precision);
	if (precision > 0)
	{
		while (i < precision && i < 6)
		{
			if (i >= precision)
				return (i);
			ft_putchar(str[i]);
			i++;
		}
	}
	else
		i = ft_putstr("(null)");
	return (i + len);
}

int		ft_put_pad_0_precision(t_format *format)
{
	char	to_print;
	int		width;

	width = format->width;
	to_print = c_padding_to_print(format);
	while (width > 0)
	{
		ft_putchar(to_print);
		width--;
	}
	return (format->width);
}

int		print_pad_s(t_format *spec, const char *str)
{
	int		nb_pad;
	char	to_print;
	int		i;

	nb_pad = diff_width_any_type(spec, str);
	to_print = c_padding_to_print(spec);
	i = 0;
	while (nb_pad > 0)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}
