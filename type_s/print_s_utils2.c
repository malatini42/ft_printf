/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:12:09 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 10:26:48 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A revoir ?
int		ft_putstr_limit(const char *str, int precision)
{
	int i;

	i = 0;
	if (precision > 0)
	{
		while (i < precision && i < 6)
		{
			if (i >= precision)
				return (i);
			ft_putchar(str[i]);
			i++;
		}
	}
	else
		i = ft_putstr("(null)");
	return (i);
}

//Je devrais faire ca a l interieur d une autre fonction ?
int		ft_put_pad_0_precision(t_format *format)
{
	char	to_print;
	int		width;

	width = format->width;
	to_print = c_padding_to_print(format);
	while (width > 0)
	{
		ft_putchar(to_print);
		width--;
	}
	return (format->width);
}

/* Pas bon
int		ft_putstr_width(const char *str, int width)
{
	int i;
	int null_length;

	null_length = 6;
	if (width > null_length)
		return (0);
	i = 0;
	while (i < width)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
*/
