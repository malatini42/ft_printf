/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:26:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 17:13:07 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

void	ft_putnbr_u(unsigned int nbr)//Le calcul est pas top
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

int 	print_pos_u_no_justify(t_format *format, unsigned int number)
{
	int i;
	int len;
	int width_to_print;
	int char_to_print;

	i = 0;
	len = 0;
	width_to_print = 0;
	char_to_print = c_padding_to_print(format);
	if (format->flags.precision == false && format->flags.width == false)
	{
		ft_putnbr_u(number);
		i += n_size_u(number);
	}
	else if (format->flags.precision == false && format->flags.width == true)
	{
		i += print_zero_pad_then_number_width(format, number, char_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == false)
	{
		i += print_zero_pad_then_number_precision(format, number, char_to_print);
	}
	else if (format->flags.precision == false && format->flags.width == true)
	{
		format->flags.zero_pad = true;
		i += print_zero_pad_then_number_width(format, number, char_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == true)
	{
			i += print_width_and_precision_pos(format, number, char_to_print);
	}
	return (i);
}

int 	print_pos_u_justify(t_format *format, unsigned int number, char print)
{
	int 	i;
	int		width_to_print;
	char	to_print;

	i = 0;
	to_print = c_padding_to_print(format);
	width_to_print = (format->width > n_size_u(number)) ? format->width - n_size_u(number) : 0;
	if (format->flags.precision == false && format->flags.width == true)
	{
		ft_putnbr_u(number);
		i += n_size_u(number);
		i += print_x_time(print, width_to_print);
	}
	else if (format->flags.precision == true && format->flags.width == true)
	{
		i += reverse_print_width_and_precision_pos(format, number, to_print);
	}
	return (i);
}

int		print_pos_u_number(t_format *format, unsigned int number)
{
	int 	i;
	char 	print;

	i = 0;
	/*
	printf("----------\n");
	printstruct(*format);
	printf("----------\n");
	*/
	print = c_padding_to_print(format);
	if (format->flags.justify_left == 0)
		i += print_pos_u_no_justify(format, number);
	else
		i += print_pos_u_justify(format, number, print);
	return (i);
}
