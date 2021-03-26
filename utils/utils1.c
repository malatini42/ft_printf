/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:38:25 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 10:27:26 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		is_correct_type(char c)
{
	if (!c)
		return (0);
	if (c == 'i' || c == 'd' || c == 'u' || c == 's' || c == 'c' ||
		c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int		ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		is_correct_spec(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '%')
		i++;
	while (s[i])
	{
		if (is_correct_type(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_putstr(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

char	c_padding_to_print(t_format *format)
{
	char	to_print;

	to_print = ' ';
	if (format->flags.zero_pad == 1)
		to_print = '0';
	return (to_print);
}
