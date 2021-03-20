/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:52:24 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:35:30 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_pad_then_number(t_format *f, int n)
{
	int		i;
	char	to_print;
	int		w_to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	w_to_print = (f->width > n_size_i(n)) ? f->width - n_size_i(n) : 0;
	i += print_x_time(to_print, w_to_print);
	i += ft_putnbr_i(n);
	return (i);
}

int		print_zero_pad_then_number_precision_i(t_format *f, int n, char c)
{
	int i;
	int len;
	int p_to_print;
	int num;

	i = 0;
	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
		i++;
	}
	len = n_size_i(num);
	p_to_print = f->precision - len;
	if (f->precision > num)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, p_to_print);
	i += ft_putnbr_i(num);
	return (i);
}

int		print_zero_pad_true_width(int n, char c, int w_to_print)
{
	int i;
	int num;

	i = 0;
	num = n;
	if (n < 0)
	{
		i += ft_putchar('-');
		num = -n;
	}
	i += print_x_time(c, w_to_print);
	i += ft_putnbr_i(num);
	return (i);
}
