/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:10:45 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 17:48:00 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		r_width_precision_pos_x(t_format *f, int n, char p, char *b)
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
	i += print_x_time('0', p_to_print);
	if (n > 0)
		i += ft_putnbr_u_base(n, b);
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

	i = 0;
	to_print = c_padding_to_print(f);
	width = (p != 0 || f->precision == 0) ? f->width - 2 : f->width;
	if (f->flags.justify_right == 0 && f->flags.precision == false &&
			f->flags.width == true)
		i += print_x_time(to_print, f->width - 3);
	else if (f->flags.precision == true && f->precision == 0)
	{
		if (f->flags.width == true)
			i += print_x_time(to_print, width);
		i += ft_putstr("0x");
		return (i);
	}
	i += ft_putstr("0x0");
	if (f->flags.precision == true && f->precision != 0)
		i += print_x_time('0', f->precision - 1);
	return (i);
}

int		n_size_u(unsigned int n)
{
	unsigned i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return ((int)i);
}

void	ft_putnbr_u(unsigned int nbr)
{
	unsigned int n;

	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
		ft_putnbr_i(n / 10);
	ft_putchar(n % 10 + '0');
}
