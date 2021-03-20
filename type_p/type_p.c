/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:47:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 20:06:43 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putnbr_p_base(unsigned long long nbr, char *base)
{
	unsigned long long	nb;
	int					temp;
	int 				base_len;
	static int			i;

	nb = nbr;
	base_len = 16;
	i = 0;
	if ((unsigned long long)(base_len - 1) < nb)
		ft_putnbr_p_base(nb / base_len, base);
	temp = base[(int)(nb % base_len)];
	write(1, &temp, 1);
	i++;
	return (i);
}

int		print_zero_pad_then_number_width_p(t_format *f, unsigned long long ptr, char c, char *b)
{
	int i;
	int len;
	int width_to_print;
	unsigned long long p;

	i = 0;
	p = ptr;
	len = count_nbr_u_base(ptr, b);
	width_to_print = f->width - len -4;
	i += print_x_time(c, width_to_print);
	i += ft_putstr("0x");
	i += ft_putnbr_p_base(ptr, b);
	return (i);
}

int		print_zero_pad_then_number_precision_p(t_format *f, unsigned long long ptr, char c, char *b)
{
	int i;
	int len;
	int p_to_print;

	i = 0;
	len = (ptr == 0) ? 0 : count_nbr_u_base(ptr, b);
	p_to_print = f->precision - len;
	c = ' ';
	if ((unsigned int)f->precision >= ptr)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, p_to_print);
	if (ptr > 0)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(ptr, b);
	}
	return (i);
}

int		print_width_and_precision_pos_p(t_format *f, unsigned long long ptr, char c, char *b)
{
	int i;
	int w_to_print;
	int p_to_print;

	p_to_print = (ptr > 0) ? 
		f->precision - count_nbr_u_base(ptr, b) : f->precision;
	if (f->precision > count_nbr_u_base(ptr, b) && ptr > 0)
		w_to_print = f->width - p_to_print - count_nbr_u_base(ptr, b);
	else
		w_to_print = f->width - count_nbr_u_base(ptr, b) - 2;
	i = 0;
	if (f->flags.zero_pad == true)
		c = ' ';
	if (f->width < f->precision)
		i += ft_putstr("0x");
	i += print_x_time(c, w_to_print);
	i += print_x_time('0', p_to_print);
	if (f->width > f->precision)
		i += ft_putstr("0x");
	i += ft_putnbr_p_base(ptr, b);
	return (i);
}

int 	print_pos_p_no_justify(t_format *f, unsigned long long ptr)
{
	int 	i;
	int 	len;
	int 	w_to_print;
	char	c_to_print;
	char 	*base;

	i = 0;
	len = 0;
	w_to_print = 0;
	base =  "0123456789abcdef";
	c_to_print = c_padding_to_print(f);
	if (f->flags.precision == false && f->flags.width == false)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(ptr, base);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += print_width_and_precision_pos_p(f, ptr, c_to_print, base);
	else if (f->flags.precision == true && f->flags.width == false)
		i += print_zero_pad_then_number_precision_p(f, ptr, '0', base);
	else if (f->flags.precision == false && f->flags.width == true)
		i+= print_zero_pad_then_number_width_p(f, ptr, c_to_print, base);
	return (i);
}

int 	print_pos_p_justify(t_format *f, unsigned long long ptr, char *b)
{
	int 	i;
	int		w_to_print;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(f);
	w_to_print = (f->width > count_nbr_u_base(ptr, b)) ? 
		f->width - count_nbr_u_base(ptr, b) : 0;
	if (f->flags.precision == false && f->flags.width == true)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(ptr, b);
		i += print_x_time(to_print, w_to_print - 4);
	}
	else if (f->flags.precision == true && f->flags.width == true)
		i += r_width_precision_u(f, ptr, to_print);
	return (i);
}

void	print_p(const char *str, t_format *f, va_list arg)
{
	void	*ptr;
	int 	i;
	char	x;
	char 	print;
	char	*base;

	i = 0;
	x = which_x_type(str);
	ptr = va_arg(arg, void *);
	base = "0123456789abcdef";
	print = c_padding_to_print(f);
	if (!ptr)
		i += handle_null_pointer(f, (unsigned long long)ptr);
	else
	{
		if (f->flags.justify_right == 0)
			i += print_pos_p_no_justify(f, (unsigned long long)ptr);
		else
			i += print_pos_p_justify(f, (unsigned long long)ptr, base);
	}
	f->printed_chars += i;
}
