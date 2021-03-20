/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:09:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:09:34 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup_until_type(const char *s1)
{
	int		i;
	int		max;
	char	*cpy;

	if (!s1)
		return (NULL);
	i = 0;
	max = len_until_end_format(s1);
	while (s1[i] && i <= max)
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i <= max)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		diff_width_for_s(t_format *f, const char *str)
{
	int	diff_width;

	if (!f && !str)
		return (0);
	diff_width = 0;
	if (f->precision == 0 && f->type == S)
		diff_width = f->width - ft_strlen(str);
	return (diff_width);
}

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

int		len_with_precision(const char *str, t_format *f)
{
	int 	i;
	int 	precision;
	char 	to_print;

	to_print = c_padding_to_print(f);
	if (!str && !f)
		return (0);
	precision = f->precision;
	if (precision == 0 && f->flags.precision == true)
		return (0);
	i = 0;
	if (!str)
		return (0);
	if (f->precision < 0 && f->flags.width == false)
	{
		ft_putstr(str);
		i += ft_strlen(str);
		f->printed_chars += i;
		return (i);
	}
	while (str[i])
	{
		if (i >= precision && precision != 0)
		{
			if (f->precision < 0 && f->width < 0)
			{
				ft_putstr(str);
				i += ft_strlen(str);
				i += print_x_time(to_print, -f->width - ft_strlen(str));
				f->printed_chars += i;
			}
			return (i);
		}
		i++;
	}
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
