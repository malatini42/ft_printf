/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 15:26:27 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_s(const char *str, t_format *format, va_list arg_ptr)
{
	int	i;
	char *s;
	(void)str;//a revoir
	i = 0;
	s = va_arg(arg_ptr, char *);
	if (format->flags.justify_left == 0)
		i += print_pad(format, s);
	//printf("%s\n", str);
	i += ft_putstr_precision(s, format);
	if (format->flags.justify_left == 1)
		i += print_pad(format, s);
	format->printed_chars += i;
}
