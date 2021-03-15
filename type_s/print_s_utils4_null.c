/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils4_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:15:38 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 15:15:55 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_null_s_justify_left(t_format *spec, int max_precision)
{
	int 	i;
	int		nb_pad;
	char	to_print;
	int		len_null;

	i = 0;
	len_null = 6;
	nb_pad = 0;
	to_print = c_padding_to_print(spec);
	if (spec->width < len_null && spec->flags.precision == false)
		i += ft_putstr("(null)");
	else if (spec->flags.precision == true)
		i += print_x_time(to_print, spec->width);
	else if (spec->width > len_null && spec->flags.precision == false)
	{
		i += ft_putstr("(null)");
		i += print_x_time(to_print, spec->width - len_null);
	}
	(void)max_precision;//a revoir
	return (i);
}