/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:42:22 by malatini          #+#    #+#             */
/*   Updated: 2021/03/25 18:33:30 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		r_width_precision_pos_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (n > 0) ? f->precision - count_nbr_u_base(n, b) : f->precision;
	if (f->precision > count_nbr_u_base(n, b) && n > 0)
		w_to_print = f->width - p_to_print - count_nbr_u_base(n, b);
	else if (n == 0)
		w_to_print = f->width - p_to_print;
	else
		w_to_print = f->width - count_nbr_u_base(n, b);
	i = 0;
	if (n_size_u(n) < 10)
		i += print_x_time('0', p_to_print);
	if (n != 0)
		i += ft_putnbr_u_base(n, b);
	else if (n == 0 && f->precision < 0)
	{
		i += ft_putnbr_i(0);
		i += print_x_time(c_padding_to_print(f), f->width - 1);
		return (i);
	}
	if (n == 0 && f->precision < 0 && f->flags.width == false)
	{
		//write(1, "coucou", 6);
		i += ft_putnbr_i(0);
	}
	if (n == 0 && f->precision == 0 && f->width < 0)
	{
		//modifier w_to_print pour eviter les returns etc
		i += print_x_time(' ', -f->width);
		return (i);
	}
	i += print_x_time(p, w_to_print);
	return (i);
}

int		zero_pad_width_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int len;

	i = 0;
	len = count_nbr_u_base(n, b);
	i += print_x_time(p, f->width - len);
	i += ft_putnbr_u_base(n, b);
	return (i);
}

int		handle_null_pointer(t_format *f, unsigned long long p)
{
	int		i;
	char	to_print;
	int		width;
	char	*b;

	i = 0;
	b = "0123456789abcdef";
	to_print = c_padding_to_print(f);
	width = f->width > 0 ? f->width - count_p_length(p, b) - 1 : - f->width - count_p_length(p, b) - 1;
	if (f->flags.justify_right == 0 && f->flags.precision == false &&
			f->flags.width == true)
		i += print_x_time(to_print, f->width - 3);
	else if (f->flags.precision == true && f->precision == 0)
	{
		if (f->flags.width == true && (f->flags.justify_right == false && f->flags.precision == true))
			i += print_x_time(to_print, width);
		i += ft_putstr("0x");
		if (f->flags.width == true && (f->flags.justify_right == true || f->flags.precision == false))
			i += print_x_time(to_print, width);
		return (i);
	}
	i += ft_putstr("0x0");
	if (f->flags.precision == true && f->precision != 0)
	{
		i += print_x_time('0', f->precision - 1);
	}
	if (f->flags.width == true && f->flags.precision == false && f->flags.justify_right == true)
	{
		i += print_x_time(c_padding_to_print(f), width - 1);
	}
	return (i);
}
