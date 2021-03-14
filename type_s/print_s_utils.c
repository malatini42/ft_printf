/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:41:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 11:23:11 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup_until_type(const char *s1)
{
	int		i;
	int		max;
	char	*cpy;

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

int		ft_putstr_precision(char *str, t_format *spec)
{
	int i;
	//int len;
	int precision;

	precision = spec->precision;
	if (precision == 0 && spec->flags.precision == true)
		return (0);
	//len = ft_strlen(str);
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
	//int len;
	int precision;

	precision = spec->precision;
	if (precision == 0 && spec->flags.precision == true)
		return (0);
	//len = ft_strlen(str);
	i = 0;
		while (str[i])
	{
		if (i >= precision && precision != 0)
			return (i);
		i++;
	}
	return (i);
}
