/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:09:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 10:14:05 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//faire une fonction pour imprimer dans un sens ou l autre pour tous les types?s
//outils print type_pc - reutilisable
char	c_padding_to_print(t_format *format)
{
	char to_print;

	to_print = ' ';
	if (format->flags.zero_pad == 1)
		to_print = '0';
	return (to_print);
}

//en cours pour pc, tester pour les autres
int		diff_width(t_format *format)
{
	int diff_width;

	diff_width = 0;
	/*
	printf("2----------------\n");
	printstruct(format);
	printf("2----------------\n");
	*/
	if (format->precision == 0)
		diff_width = format->width - 1;
	//printf("La diff width est: %i\n", diff_width);
	return (diff_width);
}

int		print_pad(t_format *spec)
{
	int		nb_pad;
	char	to_print;
	int		i;

	nb_pad = diff_width(spec);
	to_print = c_padding_to_print(spec);
	i = 0;
	while (nb_pad > 0)
	{
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}
