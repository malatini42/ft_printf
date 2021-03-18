/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:01:20 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 15:21:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Mon fr_putchar renvoie deja 1

void	print_null_c(t_format *format)
{
	int 	max_precision;
	int 	i;
	char	to_print;

	max_precision = format->precision;
	to_print = c_padding_to_print(format);
	i = 0;
	//Attention a ne pas confondre les fonctions et a ne pas faire de doublons
	if (format->flags.precision == false && format->flags.width == true && format->flags.zero_pad == false)
	{
		i += write(1, "\0", 1);
		i += print_x_time(' ', format->width - 1);
	}
	format->printed_chars += i;
}

int		print_c_no_justify(t_format *format, char c)
{
	int		i;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
		i += ft_putchar(c);
	else if (format->flags.precision == false && format->flags.width == true)
	{
		i += print_x_time(to_print, format->width -1);
		i += ft_putchar(c);//Est-ce qu'il faut "echapper" tous les characters ?
	}
	return (i);
}

void	print_c(t_format *format, va_list arg_ptr)
{
	char	c;
	int		i;

	c = va_arg(arg_ptr, int); //Promoted to int / undefined behaviour for chars
	i = 0;
	if (!c)
	{
		print_null_c(format);
		return ;
	}
	i += ft_putchar(c);
	if (format->flags.justify_left == 0)
		i += print_c_no_justify(format, c);
	/*
	if (format->flags.justify_left == 1)
		i += print_c_justify(format, c);
	*/
	format->printed_chars += i;
}
