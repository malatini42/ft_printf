/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:32 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 09:48:13 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A remettre au propre - passer en arg plutot que de faire pleins de var
int 	print_pos_no_justify(t_format *format, int number)
{
	int i;
	int len;
	int width_to_print;
	int char_to_print;

	i = 0;
	len = 0;
	width_to_print = 0;
	char_to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
	{
		ft_putnbr(number);
		i += n_size(number);
	}
	else if (format->flags.precision == false && format->flags.width == true)
	{
		i += print_zero_pad_then_number_width(format, number, char_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == false)
	{
		i += print_zero_pad_then_number_precision(format, number, char_to_print);
	}
	else if (format->flags.precision == false && format->flags.width == true)
	{
		format->flags.zero_pad = true;
		i += print_zero_pad_then_number_width(format, number, char_to_print);
	}
	return (i);
}

int 	print_pos_justify(t_format *format, int number, char print)
{
	int i;
	int	width_to_print;

	i = 0;
	width_to_print = (format->width > n_size(number)) ? format->width - n_size(number) : 0;
	if (format->flags.precision == false && format->flags.width == true)
	{
		ft_putnbr(number);
		i += n_size(number);
		i += print_x_time(print, width_to_print);
	}
	return (i);
}

//Harmoniser
int		print_pos_number(t_format *format, int number)
{
	int 	i;
	char 	print;

	i = 0;
	print = c_padding_to_print(format);
	if (format->flags.justify_left == 0)
		i += print_pos_no_justify(format, number);
	else
		i += print_pos_justify(format, number, print);
	return (i);
}
