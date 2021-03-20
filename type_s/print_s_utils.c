/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:41:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:17:44 by malatini         ###   ########.fr       */
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

int		diff_width_for_s(t_format *format, const char *str)
{
	int	diff_width;

	if (!format && !str)
		return (0);
	diff_width = 0;
	if (format->precision == 0 && format->type == S)
		diff_width = format->width - ft_strlen(str);
	return (diff_width);
}

//Renommer cette fonction qui devrait servir aussi pour la width
int		ft_putstr_precision(char *str, t_format *spec)
{
	int 	i;
	int 	precision;
	int 	len;
	char	to_print;

	precision = spec->precision;
	len = ft_strlen(str);
	to_print = c_padding_to_print(spec);
	if (precision == 0 && spec->flags.precision == true)
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
	if (spec->flags.width == true && spec->width < 0)
		i += print_x_time(to_print, -spec->width - len);
	return (i);
}

int		len_with_precision(const char *str, t_format *spec)
{
	int 	i;
	int 	precision;
	char 	to_print;

	to_print = c_padding_to_print(spec);
	if (!str && !spec)
		return (0);
	precision = spec->precision;
	if (precision == 0 && spec->flags.precision == true)
		return (0);
	i = 0;
	if (!str)
		return (0);
	if (spec->precision < 0 && spec->flags.width == false)
	{
		ft_putstr(str);
		i += ft_strlen(str);
		spec->printed_chars += i;
		return (i);
	}
	while (str[i])
	{
		if (i >= precision && precision != 0)
		{
			if (spec->precision < 0 && spec->width < 0)
			{
				ft_putstr(str);
				i += ft_strlen(str);//le retour de putstr peut marcher ?
				i += print_x_time(to_print, -spec->width - ft_strlen(str));
				spec->printed_chars += i;
			}
			return (i);
		}
		i++;
	}
	return (i);
}

int	len_until_end_format(const char *str)
{
	int i;

	i = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		if (is_correct_type(str[i]))
			return (i);
		i++;
	}
	return (0);
}
