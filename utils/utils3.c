/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:53 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 08:39:16 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		diff_width_any_type(t_format *spec, const char *str)
{
	int	diff_width;

	diff_width = 0;
	if (spec->type == S && str)
		diff_width = spec->width - len_with_precision(str, spec);
	else if (spec->type == S && !str)
		diff_width = spec->width - 6;
	else if (spec->precision == 0 && spec->type == PC)
		diff_width = spec->width - 1;
	return (diff_width);
}

int		get_width(const char *str, t_format *format)
{
	int width;
	int i;

	if (!str && !format)
		return (false);
	width = 0;
	i = 1;
	while (str[i] == '-' || str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		width = width * 10 + str[i] - '0';
		i++;
	}
	format->width = width;
	if (width != 0)
		format->flags.width = true;
	return (width);
}

int		get_precision(const char *str, t_format *format)
{
	int		precision;
	int		i;

	precision = 0;
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
		{
			format->flags.precision = true;
			break ;
		}
		if (is_correct_type(str[i]))
			return (precision);
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		precision = precision * 10 + str[i] - '0';
		i++;
	}
	format->precision = precision;
	return (precision);
}

int		get_type(const char *format)
{
	int i;

	if (!format)
		return (0);
	i = 0;
	if (format[i] == '%')
		i++;
	while (!(is_correct_type(format[i])) && format[i])
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		return (ID);
	else if (format[i] == 'u')
		return (U);
	else if (format[i] == 'c')
		return (C);
	else if (format[i] == 's')
		return (S);
	else if (format[i] == '%')
		return (PC);
	else if (format[i] == 'x' || format[i] == 'X')
		return (H);
	else if (format[i] == 'p')
		return (P);
	return (0);
}

int		handle_null_pointer(t_format *f, unsigned long long pointer)
{
	int		i;
	char	to_print;
	int		width;

	i = 0;
	to_print = c_padding_to_print(f);
	width = (pointer != 0 || f->precision == 0) ? f->width - 2 : f->width;
	if (f->flags.justify_right == 0 && f->flags.precision == false &&
			f->flags.width == true)
		i += print_x_time(to_print, f->width - 3);
	else if (f->flags.precision == true && f->precision == 0)
	{
		if (f->flags.width == true)
			i += print_x_time(to_print, width);
		i += ft_putstr("0x");
		return (i);
	}
	i += ft_putstr("0x0");
	if (f->flags.precision == true && f->precision != 0)
		i += print_x_time('0', f->precision - 1);
	return (i);
}
