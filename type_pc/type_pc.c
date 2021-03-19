/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 18:02:27 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
