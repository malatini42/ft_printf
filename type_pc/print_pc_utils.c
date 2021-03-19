/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:34:24 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 15:09:37 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//mettre dans les fichiers utils ?
int		print_pad_pc(t_format *spec, const char *str)
{
	int		nb_pad;
	char	to_print;
	int		i;

	nb_pad = diff_width_any_type(spec, str);
	to_print = c_padding_to_print(spec);
	i = 0;
	while (nb_pad > 0)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}

int		diff_width_for_pc(t_format *format)
{
	int diff_width;

	if (!format)
		return (0);
	diff_width = 0;
	if (format->precision == 0)
		diff_width = format->width - 1;
	return (diff_width);
}
