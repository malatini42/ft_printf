/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:40:30 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 21:46:00 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		found_star(const char *str)
{
	int i;
	int found;

	i = 1;
	found = 0;
	while (str[i])
	{
		if (is_correct_type(str[i]))
			return (0);
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (-1);
}

int		is_after_star(const char *str, char c)
{
	int i;

	i = 0;
	if (str[i] == '%')
		i++;
	while (str[i])
	{
		while (str[i] != '*' && str[i])
			i++;
		if (str[++i] == c)
			return (1);
		i++;
	}
	return (0);
}

//a refaire car on a eu des soucis
int		handle_star(const char *str, t_format *format, va_list arg_ptr)
{
	int star;
	int arg;

	arg = va_arg(arg_ptr, int);
	star = found_star(str);
	if (star == 1 && is_after_star(str, '.'))
	{
		format->width = arg;
		format->flags.star = true;

	}
	else if (star == 1 && !(is_after_star(str, '.')))
	{
		format->precision = arg;
		format->flags.star = true;
	}
	return (star);
}
