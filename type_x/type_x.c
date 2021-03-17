/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/17 16:47:05 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int convert_hexa(t_format *format, va_list arg_ptr, char x)
{
	int i;
	char base[17];

	if (x == 'x')
		ft_strcpy(base, "123456789abcdef");
	else if (x == 'X')
		ft_strcpy(base, "123456789ABCDEF");
	printf("%s\n", base);
	i = 0;
	(void)format;
	(void)arg_ptr;
	(void)x;
	return (0);
}

void	print_x(const char *format, t_format *format, va_list arg_ptr)
{
	int 	number;
	int 	i;
	char 	x;

	i = 0;
	x = which_x_type(format);
	/*
	printf("-------------------\n");
	printstruct(*format);
	printf("-------------------\n");
	*/
	number = va_arg(arg_ptr, int);
	//number = convert_hexa(format, arg_ptr, x);
	//Faire une fonction qui va convertir en hexa
	i += print_pos_u_number(format, number);
	format->printed_chars += i;
}
