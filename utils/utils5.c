/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:03:45 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 08:59:07 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		found_star(const char *str, t_format *format)
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
			format->flags.star = true;
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

int		handle_star(const char *str, t_format *f, va_list arg_ptr, int star)
{
	if (star == 1)
	{
		if ((after_star(str, '.') == 1) && (f->flags.width = true))
			f->width = va_arg(arg_ptr, int);
		else if (!(after_star(str, '.')) && found_char(str, '.') > 0)
		{
			f->precision = va_arg(arg_ptr, int);
			f->flags.precision = true;
		}
		else if (!(after_star(str, '.')) && !(found_char(str, '.') > 0))
		{
			f->width = va_arg(arg_ptr, int);
			f->flags.width = true;
		}
	}
	else if (star == 2)
	{
		f->width = va_arg(arg_ptr, int);
		f->flags.width = true;
		f->precision = va_arg(arg_ptr, int);
		f->flags.precision = true;
	}
	return (1);
}

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
	long		nb;
	int			temp;
	int			base_len;
	static int	i;

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
