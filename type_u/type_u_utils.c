/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:49:47 by malatini          #+#    #+#             */
/*   Updated: 2021/03/24 14:19:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		r_width_precision_u(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (n > 0) ? f->precision - n_size_u(n) : f->precision;
	if (f->precision > n_size_u(n) && n > 0)
		w_to_print = f->width - p_to_print - n_size_u(n);
	else if (n == 0)
		w_to_print = f->width - p_to_print;
	else
		w_to_print = f->width - n_size_u(n);
	i = 0;
	i += print_x_time('0', p_to_print);
	if (n != 0)
	{
		ft_putnbr_u(n);
		i += n_size_u(n);
	}
	//write(1, "coucou", 6);
	if (n == 0 && f->precision < 0 && f->width > 0)
	{
		i += ft_putnbr_i(0);
		i += print_x_time(c_padding_to_print(f), f->width - n_size_i(n));
		return (i);
	}
	if (n == 0 && f->precision < 0 && f->flags.width == false)
	{
		i += ft_putnbr_i(0);
	}
	if (n == 0 && f->precision < 0 && f->width < 0)
		i += ft_putnbr_i(0);
	if (n == 0 && f->precision == 0 && f->width < 0)
	{
		i += print_x_time(' ', -f->width);
	}
	/*
	if (n_size_i(n) >= f->precision && f->flags.zero_pad == false && f->flags.justify_right == false)
	{
		write(1, "coucou", 6);
		i += print_x_time('0', f->precision - n_size_i(n));
		ft_putnbr_u(n);
		i += n_size_u(n);
		return (i);
	}
	*/
	/*
	if (f->width == 0 && f->flags.width == true && f->flags.precision == false)
	{
		i += ft_putnbr_u_base(n, "0123456789abdef");
	}
	*/
	i += print_x_time(c, w_to_print);
	return (i);
}

int		zero_pad_precision_u(t_format *f, unsigned int n, char c)
{
	int i;
	int len;
	int p_to_print;

	i = 0;
	len = (n == 0) ? 0 : n_size_u(n);
	p_to_print = f->precision - len;
	if ((unsigned int)f->precision >= n)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	if (n == 2147483648)
	{
		return (ft_putstr("2147483648"));
	}
	if (n_size_i(n) <= f->precision && f->flags.zero_pad == false && f->flags.justify_right == false)
	{
		//write(1, "coucou", 6);
		if (n_size_u(n) < 10)
			i += print_x_time('0', f->precision - n_size_i(n));
		ft_putnbr_u(n);
		i += n_size_u(n);
		return (i);
	}
	i += print_x_time(c, p_to_print);
	i += n == 0 ? 0 : n_size_u(n);
	if (n > 0)
		ft_putnbr_u(n);
	else if (n == 0 && f->precision < 0 && f->flags.width == false)
	{
		//write(1, "coucou", 6);
		i += ft_putnbr_i(0);
	}
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

void	ft_putnbr_u(unsigned int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr_i(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		ft_putnbr_u_base(unsigned int n, char *b)
{
	long		nb;
	int			temp;
	int			base_len;
	static int	i;

	nb = n;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		ft_putnbr_u_base(nb / base_len, b);
	temp = b[(int)(nb % base_len)];
	write(1, &temp, 1);
	i++;
	return (i);
}
