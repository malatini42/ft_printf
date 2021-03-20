/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:10:45 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 11:16:58 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		count_nbr_u_base(unsigned int nbr, char *base)
{
	long			nb;
	int				temp;
	int				base_len;
	static int		i;

	nb = nbr;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		count_nbr_u_base(nb / base_len, base);
	temp = base[(int)(nb % base_len)];
	i++;
	return (i);
}

int		zero_pad_precision_x(t_format *f, unsigned int n, char p, char *b)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (n == 0) ? 0 : count_nbr_u_base(n, b);
	precision_to_print = f->precision - len;
	if ((unsigned int)f->precision >= n)
	{
		f->flags.zero_pad = true;
		p = '0';
	}
	i += print_x_time(p, precision_to_print);
	if (n > 0)
		i += ft_putnbr_u_base(n, b);
	return (i);
}

int		width_precision_pos_x(t_format *f, unsigned int n, char p, char *b)
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
	if (f->flags.zero_pad == true)
		p = ' ';
	i += print_x_time(p, w_to_print);
	i += print_x_time('0', p_to_print);
	if (n > 0)
		i += ft_putnbr_u_base(n, b);
	return (i);
}

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
