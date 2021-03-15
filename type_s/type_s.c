/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 17:16:01 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	char to_print;

	max_precision = format->precision;
	width = format->width;
	to_print = c_padding_to_print(format);
	i = 0;
	if (format->flags.justify_left == false)
		i += redirect_no_justify_left(format, to_print);
	else if (format->flags.justify_left == true)//harmoniser les noms ?
		i += print_pad_null_s_justify_left(format, max_precision);
	format->printed_chars += i;
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
