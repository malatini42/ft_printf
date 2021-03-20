/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 08:30:21 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

void	print_pc(const char *str, t_format *format)
{
	int i;

	i = 0;
	if (format->flags.justify_right == 0)
		i += print_pad_pc(format, str);
	ft_putchar('%');
	i++;
	if (format->flags.justify_right == 1)
		i += print_pad_pc(format, str);
	format->printed_chars += i;
}
