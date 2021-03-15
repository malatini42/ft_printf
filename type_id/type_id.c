/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:42:29 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 18:23:26 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_id(t_format *format, va_list arg_ptr)
{
	int number;
	int i;

	i = 0;
	number = va_arg(arg_ptr, int);
	if (number > 0)
		i += print_pos_number(format, number);
	else 
		i += print_neg_number(format, number);
	format->printed_chars += i;
	
}