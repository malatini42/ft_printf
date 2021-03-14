/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:22:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 13:11:46 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const char	*print_s(const char *str, t_format *format, va_list arg_ptr)
{
	int	i;
	char *s;
	(void)str;//a revoir

	/*
	printf("2----------------\n");
	printstruct(*format);
	printf("2----------------\n");
	*/
	i = 0;
	//Probleme avec mon justify left
	//format->flags.justify_left = false;
	s = va_arg(arg_ptr, char *);
	if (!s)
	{
		//format->printed_chars = 6; pourquoi le vrai printf renverrait un 6?
		//je ne vois pas comment retourner (null)
		ft_putstr("(null)");
		format->printed_chars = 6;
		return (str);
	}
	if (format->flags.justify_left == 0)
		i += print_pad(format, s);
	//printf("%s\n", str);
	i += ft_putstr_precision(s, format);
	if (format->flags.justify_left == 1)
		i += print_pad(format, s);
	format->printed_chars += i;
	return (str);
}
