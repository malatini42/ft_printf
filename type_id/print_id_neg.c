/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:09:34 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 19:00:36 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_neg_number(t_format *format, int number)
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
		i += n_size(number) > 2 ? ft_putnbr(number) + 1 : ft_putnbr(number);
	return (i);
}