/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:56:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 15:40:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_width(const char *str, t_format *format)
{
	int width;
	int i;

	width = 0;
	i = 1;
	while (str[i] == '-' || str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		width = width * 10 + str[i] - '0';
		i++;
	}
	format->width = width;
	return (width);
}

int		get_precision(const char *str, t_format *format)
{
	int precision;
	int i;
	int max;

	precision = 0;
	max = len_until_end_format(str);
	i = (format->type == PC) ? 1 : 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
		return (precision);
	else if (str[i] == '.' && i < max)
		format->flags.precision = true;
	i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		precision = precision * 10 + str[i] - '0';
		i++;
	}
	format->precision = precision;
	return (precision);
}

int		get_type(const char *format)
{
	int i;

	i = 0;
	if (format[i] == '%')
		i++;
	while (!(is_correct_type(format[i])) && format[i])
		i++;
	if (format[i] == 'i' || format[i] == 'd' || format[i] == 'u')
		return (UID);
	else if (format[i] == 'c')
		return (C);
	else if (format[i] == 's')
		return (S);
	else if (format[i] == '%')
		return (PC);
	else if (format[i] == 'x' || format[i] == 'X')
		return (H);
	else if (format[i] == 'p')
		return (P);
	return (0);
}

//changer de fichier pour que ce soit plus clair
void	print_type(const char *str, t_format *spec, va_list arg_ptr)
{
	int type;
	/*
	printf("\n----------------\n");
	printstruct(spec);
	printf("\n----------------\n");
	*/
	//printf("\nOUHOU!\n");
	type = spec->type;
	if (type == PC)
		print_pc(str, spec);
	else if (type == S)
	{
		print_s(str, spec, arg_ptr);
	}
	/*s
	else if (type == UID)
		return (print_uid(format));
	else if (type == C)
		return (print_c(format));

	else if (type == H)
		return (print_pc(format));s
	else if (type == P)
		return (print_p(format));
	else
		return (-1);
	*/
}
