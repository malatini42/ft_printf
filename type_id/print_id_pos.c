/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:32 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 19:07:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A remettre au propre
int 	print_pos_no_justify_left(t_format *format, int number)
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
	if (format->flags.precision == false && format->flags.width == true)
	{
		len = n_size(number);
		width_to_print = format->width - len;
		i += print_x_time(char_to_print, width_to_print);
		ft_putnbr(number);	
		i += n_size(number);
	}
	return (i);
}

int 	print_pos_justify_left(t_format *format, int number)
{
	int i;

	i = 0;
	(void)format;
	(void)number;
	return (i);
}

int		print_pos_number(t_format *format, int number)
{
	int i;

	i = 0;
	if (format->flags.justify_left == 0)
		i += print_pos_no_justify_left(format, number);
	else
		i += print_pos_justify_left(format, number);
	return (i);
}