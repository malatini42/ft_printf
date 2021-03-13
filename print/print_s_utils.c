/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:14:08 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 15:38:10 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
