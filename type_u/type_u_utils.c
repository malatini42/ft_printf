/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:49:47 by malatini          #+#    #+#             */
/*   Updated: 2021/03/29 08:58:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putnbr_u(unsigned int n)
{
	unsigned int	nb;
	int				i;

	nb = n;
	i = 0;
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	if (nb > 9)
		i += ft_putnbr_u(nb / 10);
	ft_putchar(nb % 10 + '0');
	i++;
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

int		ft_putnbr_u_base(t_format *f, unsigned int n, char *b)
{
	long		nb;
	int			temp;
	int			base_len;
	static int	i;

	(void)f;
	nb = n;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		ft_putnbr_u_base(f, nb / base_len, b);
	temp = b[(int)(nb % base_len)];
	write(1, &temp, 1);
	i++;
	return (i);
}

int		r_width_precision_u(t_format *f, unsigned int n, char c)
{
	int i;
	int w;
	int p;

	i = 0;
	if (!(f->width <= -1 && f->precision <= -1))
	{
		p = (n > 0) ? f->precision - n_size_u(n) : f->precision;
		w = calculate_w_u_r(f, n, n_size_u(n), p);
		if (n_size_u(n) < 10)
			i += print_x_time('0', p);
		if (n != 0)
			i += ft_putnbr_u(n);
		else if (n == 0)
			i = handle_n0_w_p_r(f, n, i);
		if (f->width >= 0 && f->precision < 0 && n == 0)
			w = 0;
		i += print_x_time(c, w);
	}
	else
		i = handle_neg_w_p_u(f, n, n_size_u(n), i);
	return (i);
}

int		zero_pad_precision_u(t_format *f, unsigned int n, char c)
{
	int i;
	int len;

	i = 0;
	len = (n == 0) ? 0 : n_size_u(n);
	if ((unsigned int)f->precision >= n)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	if (n == 2147483648)
		return (ft_putstr("2147483648"));
	if (n_size_i(n) <= f->precision && f->flags.zero_pad == false)
	{
		if (n_size_u(n) < 10)
			i += print_x_time('0', f->precision - n_size_i(n));
		return (i += ft_putnbr_u(n));
	}
	i += print_x_time(c, f->precision - len);
	i += n == 0 ? 0 : n_size_u(n);
	if (n > 0)
		ft_putnbr_u(n);
	else if (n == 0 && f->precision < 0 && f->flags.width == false)
		i += ft_putnbr_i(0);
	return (i);
}
