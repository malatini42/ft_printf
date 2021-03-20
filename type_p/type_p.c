/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:47:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 08:33:12 by malatini         ###   ########.fr       */
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

int		print_zero_pad_then_number_width_p(t_format *format, unsigned long long pointer, char print, char *base)
{
	int i;
	int len;
	int width_to_print;
	unsigned long long p;

	i = 0;
	p = pointer;
	len = count_nbr_u_base(pointer, base);//pb avec cette fonction ?
	width_to_print = format->width - len -4;
	i += print_x_time(print, width_to_print);
	i += ft_putstr("0x");
	i += ft_putnbr_p_base(pointer, base);
	return (i);
}

int		print_zero_pad_then_number_precision_p(t_format * format, unsigned long long pointer, char print, char *base)
{
	int i;
	int len;
	int precision_to_print;

	i = 0;
	len = (pointer == 0) ? 0 : count_nbr_u_base(pointer, base);
	precision_to_print = format->precision - len;
	print = ' ';//A mettre en argument ?
	if ((unsigned int)format->precision >= pointer)
	{
		format->flags.zero_pad = true;
		print = '0';
	}
	i += print_x_time(print, precision_to_print);
	if (pointer > 0)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(pointer, base);
	}
	return (i);
}

int		print_width_and_precision_pos_p(t_format *format, unsigned long long pointer, char print, char *base)
{
	int i;
	int width_to_print;
	int precision_to_print;

	precision_to_print = (pointer > 0) ? format->precision - count_nbr_u_base(pointer, base) : format->precision;
	if (format->precision > count_nbr_u_base(pointer, base) && pointer > 0)
		width_to_print = format->width - precision_to_print - count_nbr_u_base(pointer, base);
	else
		width_to_print = format->width - count_nbr_u_base(pointer, base) - 2;
	i = 0;
	if (format->flags.zero_pad == true)
		print = ' ';
	if (format->width < format->precision)
		i += ft_putstr("0x");
	i += print_x_time(print, width_to_print);
	i += print_x_time('0', precision_to_print);//?
	if (format->width > format->precision)
		i += ft_putstr("0x");
	i += ft_putnbr_p_base(pointer, base);
	return (i);
}

int 	print_pos_p_no_justify(t_format *format, unsigned long long pointer)
{
	int 	i;
	int 	len;
	int 	width_to_print;
	char	char_to_print;
	char 	*base;

	i = 0;
	len = 0;
	width_to_print = 0;
	base =  "0123456789abcdef";
	char_to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(pointer, base);
	}
	else if (format->flags.precision == true && format->flags.width == true)
		i += print_width_and_precision_pos_p(format, pointer, char_to_print, base);
	else if (format->flags.precision == true && format->flags.width == false)
		i += print_zero_pad_then_number_precision_p(format, pointer, '0', base);
	else if (format->flags.precision == false && format->flags.width == true)
		i+= print_zero_pad_then_number_width_p(format, pointer, char_to_print, base);
	return (i);
}

int 	print_pos_p_justify(t_format *format, unsigned long long pointer, char *base)
{
	int 	i;
	int		width_to_print;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	width_to_print = (format->width > count_nbr_u_base(pointer, base)) ? format->width - count_nbr_u_base(pointer, base) : 0;
	//revoir s il y a pas des conditions doublons
	if (format->flags.precision == false && format->flags.width == true)
	{
		i += ft_putstr("0x");
		i += ft_putnbr_p_base(pointer, base);
		//i += count_nbr_u_base(pointer, base);
		i += print_x_time(to_print, width_to_print - 4);
	}
	else if (format->flags.precision == true && format->flags.width == true)
		i += reverse_print_width_and_precision_pos_u(format, pointer, to_print);
	return (i);
}

int		print_pos_p_number(t_format *format, unsigned long long pointer)
{
	int 	i;
	char 	print;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	print = c_padding_to_print(format);
	if (format->flags.justify_right == 0)
		i += print_pos_p_no_justify(format, pointer);
	else
		i += print_pos_p_justify(format, pointer, base);
	return (i);
}


void	print_p(const char *str, t_format *format, va_list arg_ptr)
{
	void*	pointer;
	int 				i;
	char 				x;

	i = 0;
	x = which_x_type(str);
	pointer = va_arg(arg_ptr, void *);
	if (!pointer)
		i += handle_null_pointer(format, (unsigned long long)pointer);//revoir si le parametre est utile
	else
		i += print_pos_p_number(format, (unsigned long long)pointer);
	format->printed_chars += i;//verifier
}
