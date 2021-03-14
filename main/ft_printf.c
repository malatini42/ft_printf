/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:49:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 13:23:01 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Verifier qu on a bien le bon nombre d element dans va_list?
// tests ok jusqu au 60
//gerer la condition du - sur les string
int		parse(const char *format, va_list arg_ptr)
{
	t_format	*spec;
	int			len;
	int			printed_chars;

	len = 0;
	spec = ft_initialize_struct();
	//marche pas pour %
	//printf("\nLa string est : %s\n", &format[i]);
	fill_struct(format, spec);//Attention a ne pas envoyer des mauvais type!!
	if (found_star(format))
		handle_star(format, spec, arg_ptr);
	print_type(format, spec, arg_ptr);
	printed_chars = spec->printed_chars;
	return (printed_chars);
}

void	print_type(const char *str, t_format *spec, va_list arg_ptr)
{
	int type;
	/*
	printf("\n----------------\n");
	printstruct(spec);
	printf("\n----------------\n");
	*/
	//printf("\nOUHOU!\n");
	type = spec->type;
	if (type == PC)
		print_pc(str, spec);
	else if (type == S)
	{
		print_s(spec, arg_ptr);
	}
	/*s
	else if (type == UID)
		return (print_uid(format));
	else if (type == C)
		return (print_c(format));

	else if (type == H)
		return (print_pc(format));s
	else if (type == P)
		return (print_p(format));
	else
		return (-1);
	*/
}

//Voir si on devrait ajouter une variable pour suivre sur quel caractere on se trouve
//Attention differencier i et de printed chars
int		ft_printf(const char *format, ...)
{
	int 		printed_chars;
	va_list 	arg_ptr;
	int			i;
	//t_format 	spec;

	printed_chars = 0;
	i = 0;
	//spec = ft_initialize_struct();
	//printstruct(spec);
	va_start(arg_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(is_correct_spec(&format[i])))
				return (0);
			printed_chars += parse(&format[i], arg_ptr);//Attention valeur de retour pas ok
			i += len_until_end_format(&format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (printed_chars);
}
