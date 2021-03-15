/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:41:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 08:30:30 by malatini         ###   ########.fr       */
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

int		ft_putstr_precision(char *str, t_format *spec)
{
	int i;
	//int len;
	int precision;

	if (!str && !spec)
		return (0);
	precision = spec->precision;
	if (precision == 0 && spec->flags.precision == true)
		return (0);
	//len = ft_strlen(str);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i >= precision && precision != 0)
			return (i);
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		len_with_precision(const char *str, t_format *spec)
{
	int i;
	int precision;

	if (!str && !spec)
		return (0);
	precision = spec->precision;
	if (precision == 0 && spec->flags.precision == true)
		return (0);
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i >= precision && precision != 0)
			return (i);
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
		//printf("On est la : %c\n", str[i]);
		if (is_correct_type(str[i]))
			return (i);
		i++;
	}
	return (0);
}
