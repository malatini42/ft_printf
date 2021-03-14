/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:20:41 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 14:33:23 by malatini         ###   ########.fr       */
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
//Faire une fonction qui ressemble les calculs pour la width diff ?
int		diff_width_for_pc(t_format *format)
{
	int diff_width;

	if (!format)
		return (0);
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

//Faire une fonction qui ressemble les calculs pour la width diff ?
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

//A revoir - va surement etre trop long
int		diff_width_any_type(t_format *spec, const char *str)
{
	int	diff_width;

	diff_width = 0;
	//verifier les deux premieres conditions et comment condenser
	if (spec->type == S && str)
		diff_width = spec->width - len_with_precision(str, spec);
	else if (spec->type == S && !str)
	{
		diff_width = spec->width - 6;
	}
	/*
	else if (spec->precision != 0 && spec->type == S)
		diff_width = spec->width - spec->precision + 1;
	*/
	else if (spec->precision == 0 && spec->type == PC)
		diff_width = spec->width - 1;
	return (diff_width);
}

//A revoir
int		print_pad(t_format *spec, const char *str)
{
	int		nb_pad;
	char	to_print;
	int		i;
	//int		precision;
	//int		len;

	nb_pad = diff_width_any_type(spec, str);
	to_print = c_padding_to_print(spec);
	i = 0;
	//len = ft_strlen(str);
	//precision = spec->precision;
	while (nb_pad > 0)
	{
		/* Pas bon
		if (spec->type == S && i > len)
			return (i);
		*/
		ft_putchar(to_print);
		i++;
		nb_pad--;
	}
	return (i);
}
