/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:34 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 08:37:14 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int 	print_neg_no_justify(t_format *format, int number, char print)
{
	int i;
	int width_to_print;

	i = 0;
	width_to_print = (format->width > n_size(number)) ? format->width - n_size(number) : 0;//a mettre dans la fonction d ensemble ?
	if (format->flags.precision == false && format->flags.width == true)
	{
		i += print_x_time(print, width_to_print);
		ft_putnbr(number);//revoir le putnbr pour qu il fasse 2 en 1
		i += n_size(number);
	}
	else if (format->flags.precision == false && format->flags.width == false
		&& format->flags.justify_left == false)
		i += n_size(number) > 2 ? ft_putnbr(number) + 1 : ft_putnbr(number);
	return (i);
}

int 	print_neg_justify(t_format *format, int number, char print)
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

int		print_neg_number(t_format *format, int number)
{
	int i;
	int len;
	//int width_to_print;
	int char_to_print;

	i = 0;
	len = 0;
	//width_to_print = 0;
	char_to_print = c_padding_to_print(format);
	if (format->flags.justify_left == false)
		i += print_neg_no_justify(format, number, char_to_print);
	else if (format->flags.justify_left == true)
		i += print_neg_justify(format, number, char_to_print);
	return (i);
}
