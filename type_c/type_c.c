/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:01:20 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 17:06:37 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_null_c(t_format *f)
{
	int		i;
	char	to_print;

	to_print = c_padding_to_print(f);
	i = 0;
	if (f->flags.width == true && f->flags.justify_right == false)
		i += print_x_time(' ', f->width - 1);
	i += write(1, "\0", 1);
	if (f->flags.width == true && f->flags.justify_right == true)
		i += print_x_time(' ', f->width - 1);
	f->printed_chars += i;
	return (i);
}

int		handle_special_maxs(t_format *f, unsigned int n, int i)
{
	int abs_width;

	abs_width = f->width > 0 ? f->width : f->width;
	if (f->type == H && ((abs_width >= 21 && (((int)n == INT_MIN ||
		(int)n == CHAR_MIN))) || (n == UINT_MAX && f->precision >= 10)))
		i += print_x_time('0', 2);
	return (i);
}

int		print_c_no_justify(t_format *f, int c)
{
	int		i;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == true)
		i += print_x_time(to_print, f->width - 1);
	else if (f->flags.precision == true && f->flags.width == true
		&& f->precision == 0)
		i += print_x_time(to_print, f->width - 1);
	i += ft_putchar(c);
	return (i);
}

int		print_c_justify(t_format *f, int c)
{
	int		i;
	char	to_print;
	int		w_to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	w_to_print = f->width > 0 ? f->width : -f->width;
	i += ft_putchar(c);
	if (f->flags.precision == false && f->flags.width == true)
		i += print_x_time(to_print, w_to_print - 1);
	else if (f->flags.precision == true && f->flags.width == true
		&& f->precision == 0)
		i += print_x_time(to_print, w_to_print - 1);
	return (i);
}

void	print_c(t_format *f, va_list arg)
{
	int	c;
	int	i;

	c = va_arg(arg, int);
	i = 0;
	if (f->flags.justify_right == 0)
		i += print_c_no_justify(f, c);
	else if (f->flags.justify_right == 1)
		i += print_c_justify(f, c);
	f->printed_chars += i;
}
