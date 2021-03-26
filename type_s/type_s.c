/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 13:42:39 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_s(t_format *f, const char *s)
{
	int		nb_pad;
	char	to_print;
	int		i;

	nb_pad = diff_width_any_type(f, s);
	to_print = c_padding_to_print(f);
	i = 0;
	while (nb_pad > 0)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}

void	print_null_s(t_format *f)
{
	int		max_precision;
	int		i;
	int		width;
	char	to_print;

	max_precision = f->precision;
	width = f->width;
	to_print = c_padding_to_print(f);
	i = 0;
	if (f->flags.justify_right == false)
		i += null_s_no_justify(f);
	else if (f->flags.justify_right == true)
		i += null_s_justify(f);
	f->printed_chars += i;
}

void	print_s(t_format *f, va_list arg)
{
	int		i;
	char	*s;
	int		len;

	s = va_arg(arg, char *);
	if (!s)
	{
		print_null_s(f);
		return ;
	}
	len = ft_strlen(s);
	i = 0;
	if (f->flags.justify_right == 0)
		i += print_pad_s(f, s);
	if (f->precision >= 0)
		i += ft_putstr_precision(s, f);
	if (f->precision == 0 && f->flags.precision == true
		&& f->width < 0 && f->flags.width == true)
		i += print_x_time(c_padding_to_print(f), -f->width);
	else if (f->precision < 0)
		i += ft_putstr_neg_precision(s);
	if (f->flags.justify_right == 1)
		i += print_pad_s(f, s);
	f->printed_chars += i;
}
