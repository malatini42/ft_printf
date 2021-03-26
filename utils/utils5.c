/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:03:45 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 13:06:13 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		found_star(const char *str, t_format *f)
{
	int i;
	int star;

	i = 1;
	star = 0;
	while (str[i])
	{
		if (str[i] == '*' && str[i])
		{
			++star;
			f->flags.star = true;
		}
		if (is_correct_type(str[i]) && str[i])
			return (star);
		i++;
	}
	return (-1);
}

int		after_star(const char *str, char c)
{
	int i;

	i = 0;
	if (str[i] == '%')
		i++;
	while (str[i] != '*' && str[i])
		i++;
	i++;
	if (str[i] == c)
		return (1);
	return (0);
}

void	set_neg_width(t_format *f)
{
	f->width = -f->width;
	f->flags.justify_right = true;
	f->flags.zero_pad = false;
}

void	handle_two_stars(t_format *f, va_list arg)
{
	f->width = va_arg(arg, int);
	f->flags.width = true;
	if (f->width < 0)
		if (f->flags.justify_right == false)
			set_neg_width(f);
	f->precision = va_arg(arg, int);
	f->flags.precision = true;
}

int		handle_star(const char *str, t_format *f, va_list arg, int star)
{
	if (star == 1)
	{
		if (after_star(str, '.') == 1 && found_char(str, '.') > 0)
		{
			f->width = va_arg(arg, int);
			if (f->width < 0 && f->flags.justify_right == false)
				set_neg_width(f);
			f->flags.width = true;
		}
		else if (!(after_star(str, '.')) && found_char(str, '.') > 0)
		{
			f->precision = va_arg(arg, int);
			f->flags.precision = true;
		}
		else if (!(after_star(str, '.')) && !(found_char(str, '.') > 0))
		{
			f->width = va_arg(arg, int);
			if (f->width < 0 && f->flags.justify_right == false)
				set_neg_width(f);
			f->flags.width = true;
		}
	}
	else if (star == 2)
		handle_two_stars(f, arg);
	return (1);
}
