/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:53 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 18:03:21 by malatini         ###   ########.fr       */
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
		diff_width = spec->width - 6;//attention ?
	else if (spec->precision == 0 && spec->type == PC)
		diff_width = spec->width - 1;
	return (diff_width);
}

//utilise ?? a "rationaliser" ?
int		print_pad_pc(t_format *spec, const char *str)
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
	int precision;
	int i;
	bool found;

	precision = 0;
	found = false;
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
		{
			format->flags.precision = true;
			break;
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