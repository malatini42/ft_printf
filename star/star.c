/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:40:30 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 10:13:51 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		found_star(const char *str)
{
	int i;
	int star;

	i = 1;
	star = 0;
	while (str[i])
	{
		if (str[i] == '*' && str[i])
			++star;
		if (is_correct_type(str[i]) && str[i])
			return (star);
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

//a remettre au propre
int		handle_star(const char *str, t_format *format, va_list arg_ptr)
{
	int star;
	int arg;

	arg = va_arg(arg_ptr, int);
	//je repasse dans une boucle pour tester alors que je devrais l envoyer directement dans l argument
	star = found_star(str);
	if (star > 0)
		format->flags.star = true;
	if (star == 1 && is_after_star(str, '.') == 1)
	{
		format->width = arg;
		format->flags.width = true;
	}
	else if (star == 1 && !(is_after_star(str, '.')) && found_char(str, '.') > 0)
	{
		format->precision = arg;
		format->flags.precision = true;
	}
	else if (star == 1 && !(is_after_star(str, '.')) && !(found_char(str, '.') > 0))
	{
		format->width = arg;
		format->flags.width = true;
	}
	else if (star == 1 && !(is_after_star(str, '.')) && !(found_char(str, '.') > 0))
	{
		format->width = arg;
		format->flags.width = true;
	}
	else if (star == 2)
	{
		format->width = arg;
		format->flags.width = true;
		arg = va_arg(arg_ptr, int);
		format->precision = arg;
		format->flags.precision = true;
	}
	return (1);
}
