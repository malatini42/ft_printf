/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:45:38 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 15:09:03 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	which_x_type(const char *format)
{
	int i;

	if (!format)
		return (0);
	i = 0;
	if (format[i] == '%')
		i++;
	while (!(is_correct_type(format[i])) && format[i])
		i++;
	if (format[i] == 'x')
		return ('x');
	else if (format[i] == 'X')
		return ('X');
	return (0);
}

int		ft_putnbr_u_base(unsigned int nbr, char *base)
{
	long			nb;
	int				temp;
	int 			base_len;
	static int		i;

	nb = nbr;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		ft_putnbr_u_base(nb / base_len, base);
	temp = base[(int)(nb % base_len)];
	write(1, &temp, 1);
	i++;
	return (i);
}

int		count_nbr_u_base(unsigned int nbr, char *base)
{
	long			nb;
	int				temp;
	int 			base_len;
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

int		print_zero_pad_then_number_precision_x(t_format * format, unsigned int number, char print, char *base)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (number == 0) ? 0 : count_nbr_u_base(number, base);
	precision_to_print = format->precision - len;
	if ((unsigned int)format->precision >=number)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	if (number > 0)
		i += ft_putnbr_u_base(number, base);
	return (i);
}

int		print_width_and_precision_pos_x(t_format *format, unsigned int number, char print, char *base)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = (number > 0) ? format->precision - count_nbr_u_base(number, base) : format->precision;
	if (format->precision > count_nbr_u_base(number, base) && number > 0)
		width_to_print = format->width - precision_to_print - count_nbr_u_base(number, base);//Si le resultat est positif
	else if (number == 0)
		width_to_print = format->width - precision_to_print;
	else
		width_to_print = format->width - count_nbr_u_base(number, base);
	i = 0;
	if (format->flags.zero_pad == true)
		print = ' ';
	i += print_x_time(print, width_to_print);
	i += print_x_time('0', precision_to_print);
	if (number > 0)
	{
		i += ft_putnbr_u_base(number, base);
	}
	return (i);
}

int		reverse_print_width_and_precision_pos_x(t_format *format, int number, char print, char *base)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = (number > 0) ? format->precision - count_nbr_u_base(number, base) : format->precision;
	if (format->precision > count_nbr_u_base(number, base) && number > 0)
		width_to_print = format->width - precision_to_print - count_nbr_u_base(number, base);
	else if (number == 0)
		width_to_print = format->width - precision_to_print;
	else
		width_to_print = format->width - count_nbr_u_base(number, base);
	i = 0;
	i += print_x_time('0', precision_to_print);
	if (number > 0)
	{
		i += ft_putnbr_u_base(number, base);
	}
	i += print_x_time(print, width_to_print);
	return (i);
}

int		print_zero_pad_then_number_width_x(t_format *format, unsigned int number, char print, char *base)
{
	int i;
	int len;
	int width_to_print;
	int num;

	i = 0;
	num = number;
	len = count_nbr_u_base(number, base);
	width_to_print = format->width - len;
	i += print_x_time(print, width_to_print);
	i += ft_putnbr_u_base(number, base);
	//i += n_size_i(num);
	return (i);
}
