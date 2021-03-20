/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils4_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:15:38 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 12:28:43 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Attention aux noms pour la droite/gauche il y a eu confusion
int		width_precision_null_left(t_format *format)
{
	int		len;
	int		width_to_print;
	char	to_print;
	int		i;
	char	*n;

	len = format->precision;
	width_to_print = len < 6 ? format->width - len : format->width - 6;
	i = 0;
	n = ft_strdup("(null)");
	to_print = c_padding_to_print(format);
	while (i < 6 && i < format->precision)
	{
		ft_putchar(n[i]);
		i++;
	}
	i += print_x_time(to_print, width_to_print);
	free (n);
	return (i);
}

//refaire le nom des fonctions et reorganiser
int		null_s_justify(t_format *spec)
{
	int 	i;
	int		nb_pad;
	char	to_print;
	int		len_null;

	i = 0;
	len_null = 6;
	nb_pad = 0;
	to_print = c_padding_to_print(spec);
	//devrait etre gere dans la fonction sur les chaines null ?
	if (spec->width < len_null && spec->flags.precision == false)
		i += ft_putstr("(null)");
	else if (spec->flags.precision == true && spec->flags.width == true)
		i += width_precision_null_left(spec);
	else if (spec->flags.precision == true && spec->flags.width == false)
		i += print_x_time(to_print, spec->width);
	else if (spec->width > len_null && spec->flags.precision == false)
	{
		i += ft_putstr("(null)");
		i += print_x_time(to_print, spec->width - len_null);
	}
	return (i);
}
