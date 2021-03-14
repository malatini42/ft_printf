/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 16:41:26 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//revoir cette partie
//revoir la precision
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

void	print_null_s(t_format *format, char *arg)
{
	/*
	printf("\n----------------\n");
	printstruct(*format);
	printf("\n----------------\n");
	*/
	//je compare d abord la precison puis en fonction je peux gerer la width
	int length;

	if (format->flags.justify_left == 0)
		print_pad_s(format, NULL);
	length = ft_putstr_limit("(null)", format->precision);
	if (format->flags.justify_left == 1)
		print_pad_s(format, arg);
	if (format->width > 0 && format->width > 6)
		format->printed_chars += 6 + (format->width - 6);
	else if (format->width > 0 && format->width < 6)
		format->printed_chars += 6;
	else if (format->width == 0 && format->precision > 0 && format->precision <= 6)
		format->printed_chars += length;
	else if (format->width == 0 && format->precision > 0 && format->precision > 6)
		format->printed_chars += 6;
	else if (format->width == 0 && format->precision == 0)
		format->printed_chars += 6;
}


void	print_s(t_format *format, va_list arg_ptr)
{
	int	i;
	char *s;

	i = 0;
	s = va_arg(arg_ptr, char *);
	if (!s)
	{
		print_null_s(format, s);
		return ;
	}
	//Faire une fonction pour les chaine null ?
	if (format->flags.justify_left == 0)
		i += print_pad_s(format, s);
	i += ft_putstr_precision(s, format);
	if (format->flags.justify_left == 1)
		i += print_pad_s(format, s);
	format->printed_chars += i;
}
