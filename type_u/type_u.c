/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:23:14 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 16:37:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u(t_format *format, va_list arg_ptr)
{
	unsigned int number;
	int i;

	i = 0;
	number = va_arg(arg_ptr, unsigned int);
	i += print_pos_number(format, number);
	format->printed_chars += i;
}