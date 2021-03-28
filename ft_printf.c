/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 10:50:03 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(const char *str, t_format *spec, va_list arg_ptr)
{
	int	type;

	type = spec->type;
	if (type == PC)
		print_pc(str, spec);
	else if (type == S)
		print_s(spec, arg_ptr);
	else if (type == ID)
		print_id(spec, arg_ptr);
	else if (type == U)
		print_u(spec, arg_ptr);
	else if (type == H)
		print_x(str, spec, arg_ptr);
	else if (type == P)
		print_p(str, spec, arg_ptr);
	else if (type == C)
		print_c(spec, arg_ptr);
	return (-1);
}

int		parse(const char *format, va_list arg_ptr)
{
	t_format	*spec;
	int			printed_chars;
	int			star;

	spec = ft_initialize_struct();
	fill_struct(format, spec);
	if ((star = found_star(format, spec)) > 0)
		handle_star(format, spec, arg_ptr, star);
	print_type(format, spec, arg_ptr);
	printed_chars = spec->printed_chars;
	free(spec);
	return (printed_chars);
}

int		ft_printf(const char *format, ...)
{
	int			printed_chars;
	va_list		arg_ptr;
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
