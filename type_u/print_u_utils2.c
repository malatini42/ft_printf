/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:51:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 19:14:48 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A faire - en reprenant celle des int
int		print_zero_pad_then_number_precision_u(t_format * format, unsigned int number, char print)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (number == 0) ? 0 : n_size_u(number);
	precision_to_print = format->precision - len;
	if ((unsigned int)format->precision >=number)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	if (number > 0)
		ft_putnbr_u(number);
	i += number == 0 ? 0 : n_size_u(number);
	return (i);
}