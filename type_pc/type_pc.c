/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:16:16 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:45:08 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		count_total_pc(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count++;
			if (str[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (count);
}

int		print_pad_pc(t_format *f, const char *str)
{
	int		nb_pad;
	char	to_print;
	int		i;

	nb_pad = diff_width_any_type(f, str);
	to_print = c_padding_to_print(f);
	i = 0;
	while (nb_pad > 0)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}

void	print_pc(const char *str, t_format *f)
{
	int i;

	i = 0;
	if (f->flags.justify_right == 0)
		i += print_pad_pc(f, str);
	ft_putchar('%');
	i++;
	if (f->flags.justify_right == 1)
		i += print_pad_pc(f, str);
	f->printed_chars += i;
}
