/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:52:02 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 13:40:40 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr_neg_precision(char *str)
{
	int	i;

	i = 0;
	i += ft_putstr(str);
	return (i);
}

int		ft_putstr_precision(char *str, t_format *f)
{
	int		i;
	int		precision;
	int		len;
	char	to_print;

	precision = f->precision;
	len = ft_strlen(str);
	to_print = c_padding_to_print(f);
	if (precision == 0 && f->flags.precision == true)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i >= precision && precision != 0)
			return (i);
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_putstr_limit(const char *s, int preci, int w, t_format *f)
{
	int		i;
	int		a_width;
	int		j;

	i = 0;
	j = 0;
	a_width = f->width > 0 ? f->width : -f->width;
	if (w > 0 && ((preci > ft_strlen(s) && preci > 0) || preci < 0))
		j += print_x_time(c_padding_to_print(f), a_width - 6);
	else if (w > 0 && preci <= ft_strlen(s) && preci > 0)
		j += print_x_time(c_padding_to_print(f), a_width - preci);
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
	return (i + j);
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

int		len_until_end_format(const char *s)
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
