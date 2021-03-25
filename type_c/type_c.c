/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:01:20 by malatini          #+#    #+#             */
/*   Updated: 2021/03/25 11:26:54 by malatini         ###   ########.fr       */
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

int		print_c_no_justify(t_format *f, int c)
{
	int		i;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putchar(c);
	else if (f->flags.precision == false && f->flags.width == true)
	{
		i += print_x_time(to_print, f->width - 1);
		i += ft_putchar(c);
	}
	//a remettre au propre
	else if (f->flags.precision == true && f->flags.width == true && f->precision == 0)
	{
		i += print_x_time(to_print, f->width - 1);
		i += ft_putchar(c);
	}
	else if (f->flags.precision == true && f->flags.width == false)
	{
		i += ft_putchar(c);
	}
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
	if (f->flags.precision == false && f->flags.width == false)
		i += ft_putchar(c);
	else if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putchar(c);
		i += print_x_time(to_print, w_to_print - 1);
	}
	//a remettre au propre
	else if (f->flags.precision == true && f->flags.width == true && f->precision == 0)
	{
		i += ft_putchar(c);
		i += print_x_time(to_print, w_to_print -1);
	}
	else if (f->flags.precision == true && f->flags.width == false)
	{
		i += ft_putchar(c);
	}
	return (i);
}

void	print_c(t_format *f, va_list arg)
{
	int	c;
	int	i;

	c = va_arg(arg, int);
	i = 0;
	if (!c)
	{
		print_null_c(f);
		return ;
	}
	if (f->flags.justify_right == 0)
		i += print_c_no_justify(f, c);
	else if (f->flags.justify_right == 1)
		i += print_c_justify(f, c);
	f->printed_chars += i;
}
