/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:52:02 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 19:14:05 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr_precision(char *str, t_format *f)
{
	int 	i;
	int 	precision;
	int 	len;
	char	to_print;

	precision = f->precision;
	len = ft_strlen(str);
	to_print = c_padding_to_print(f);
	if (precision == 0 && f->flags.precision == true)
		return (0);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i >= precision && precision != 0)
			return (i);
		ft_putchar(str[i]);
		i++;
	}
	if (f->flags.width == true && f->width < 0)
		i += print_x_time(to_print, -f->width - len);
	return (i);
}

int		ft_putstr_limit(const char *s, int preci, int w, char c)
{
	int 	i;
	int		len;

	i = 0;
	len = 0;
	if (w > 0)
		len += print_x_time(c, w - preci);
	if (preci > 0)
	{
		while (i < preci && i < 6)
		{
			if (i >= preci)
				return (i);
			ft_putchar(s[i]);
			i++;
		}
	}
	else
		i = ft_putstr("(null)");
	return (i + len);
}

int		ft_put_pad_0_precision(t_format *f)
{
	char	to_print;
	int		width;

	width = f->width;
	to_print = c_padding_to_print(f);
	while (width > 0)
	{
		ft_putchar(to_print);
		width--;
	}
	return (f->width);
}

int		zero_pad_width(t_format *f, int n, char c)
{
	int i;
	int w_to_print;
	int num;

	i = 0;
	num = n;
	if (n < 0 && f->flags.zero_pad == true)
	{
		ft_putchar('-');
		num = -n;
	}
	w_to_print = f->width - n_size_i(num);
	if ((int)f->width > -num && num < 0)
	{
		f->flags.zero_pad = true;
		c = '0';
	}
	i += print_x_time(c, w_to_print);
	i += ft_putnbr_i(num);
	if (f->flags.precision == false && f->flags.width == true
		&& f->width < 0 && n > 0)
		i += print_x_time(c, -f->width - n_size_i(num));
	return (i);
}

int	len_until_end_format(const char *s)
{
	int i;

	i = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (is_correct_type(s[i]))
			return (i);
		i++;
	}
	return (0);
}