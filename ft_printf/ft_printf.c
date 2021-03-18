/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 14:09:00 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		parse(const char *format, va_list arg_ptr)
{
	t_format	*spec;
	int			len;
	int			printed_chars;

	len = 0;
	spec = ft_initialize_struct();
	fill_struct(format, spec);
	if (found_star(format))
		handle_star(format, spec, arg_ptr);
	print_type(format, spec, arg_ptr);
	printed_chars = spec->printed_chars;
	return (printed_chars);
}

int		ft_printf(const char *format, ...)
{
	int 		printed_chars;
	va_list 	arg_ptr;
	int			i;

	printed_chars = 0;
	i = 0;
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(is_correct_spec(&format[i])))
				return (0);
			printed_chars += parse(&format[i], arg_ptr);
			i += len_until_end_format(&format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (printed_chars);
}
