/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 12:24:06 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Pourquoi on aurait besoin de str ? A priori pas besoin

void	print_pc(t_format *format)
{
	int i;

	i = 0;
	if (format->flags.justify_left == 0)
		i += print_pad(format);
	ft_putchar('%');
	i++;
	if (format->flags.justify_left == 1)
		i += print_pad(format);
	format->printed_chars += i;
}
