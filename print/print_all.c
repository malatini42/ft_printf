/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:20:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 16:38:34 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	c_padding_to_print(t_format *format)
{
	char to_print;

	to_print = ' ';
	if (format->flags.zero_pad == 1)
		to_print = '0';
	return (to_print);
}

int		diff_width_any_type(t_format *spec, const char *str)
{
	int	diff_width;

	diff_width = 0;
	if (spec->type == S && str)
		diff_width = spec->width - len_with_precision(str, spec);
	else if (spec->type == S && !str)
	{
		diff_width = spec->width - 6;
	}
	else if (spec->precision == 0 && spec->type == PC)
		diff_width = spec->width - 1;
	return (diff_width);
}
