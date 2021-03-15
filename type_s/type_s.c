/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 13:38:47 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//faudrait remettre ca au propre
//Ma width est mal calculee
int		redirect_no_justify_left(t_format *format)
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
		i += ft_putstr_limit("(null)", max_precision);
	return (i);
}

//rassembler les deux fonctions ?
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

//rassembler les deux fonctions ?
int		print_pad_null_s_justify_left(t_format *spec, int max_precision)
{
	int 	i;
	int		nb_pad;
	char	to_print;
	int		len_null;

	i = 0;
	len_null = 6;
	nb_pad = 0;
	to_print = c_padding_to_print(spec);
	if (spec->width < len_null && spec->flags.precision == false)
		i += ft_putstr("(null)");
	else if (spec->flags.precision == true)//spec->width < len_null &&
	{
		i += print_x_time(to_print, spec->width);
	}
	else if (spec->width > len_null && spec->flags.precision == false)
	{
		i += ft_putstr("(null)");
		i += print_x_time(to_print, spec->width - len_null);
	}
	(void)max_precision;
	return (i);
}

void	print_null_s(t_format *format)
{
	/*
	printf("\n----------------\n");
	printstruct(*format);
	printf("\n----------------\n");
	*/
	int max_precision;
	int i;
	int	width;

	max_precision = format->precision;
	width = format->width;
	i = 0;
	if (format->flags.justify_left == false)
		i += redirect_no_justify_left(format);
	else if (format->flags.justify_left == 1)
		i += print_pad_null_s_justify_left(format, max_precision);
	format->printed_chars += i;
}

//remettre au propre
int		print_pad_s(t_format *spec, const char *str, int length)
{
	int		nb_pad;
	char	to_print;
	int		i;
	(void)length;

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

void	print_s(t_format *format, va_list arg_ptr)
{
	int		i;
	char 	*s;
	int		len;

	s = va_arg(arg_ptr, char *);
	if (!s)
	{
		print_null_s(format);
		return ;
	}
	i = 0;
	len = ft_strlen(s);
	//Faire une fonction pour les chaine null ?
	if (format->flags.justify_left == 0)
		i += print_pad_s(format, s, len);
	i += ft_putstr_precision(s, format);
	if (format->flags.justify_left == 1)
		i += print_pad_s(format, s, len);
	format->printed_chars += i;
}
