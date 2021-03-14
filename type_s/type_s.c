/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 15:53:16 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


//trouver un mouyen plus propre / joli de rassembler
void	print_null_s(t_format *format, char *arg)
{
	/*
	printf("\n----------------\n");
	printstruct(*format);
	printf("\n----------------\n");
	*/
	int length;

	if (format->flags.justify_left == 0)
		print_pad(format, NULL);
	length = ft_putstr_limit("(null)", format->precision);
	if (format->flags.justify_left == 1)
		print_pad(format, arg);
	if (format->width > 0 && format->width > 6)
		format->printed_chars += 6 + (format->width - 6);
	else if (format->width > 0 && format->width < 6)
		format->printed_chars += 6;
	else if (format->width == 0 && format->precision > 0 && format->precision <= 6)
		format->printed_chars += length;
	else if (format->width == 0 && format->precision > 0 && format->precision > 6)
		format->printed_chars += 6;
	else if (format->width == 0 && format->precision == 0)
		format->printed_chars += length;
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
		i += print_pad(format, s);
	i += ft_putstr_precision(s, format);
	if (format->flags.justify_left == 1)
		i += print_pad(format, s);
	format->printed_chars += i;
}
