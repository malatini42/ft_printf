/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:32 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 18:30:22 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int 	print_pos_no_justify_left(t_format *format, int number)
{
	int i;

	i = 0;
	if (format->flags.precision == false && format->flags.width == false)
		i += ft_putnbr(number);
	(void)format;
	(void)number;
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