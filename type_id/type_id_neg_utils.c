/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id_neg_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:59:50 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 12:03:17 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	width_precision_neg_no_justify(t_format *f, int n, char c)
{
	int i;

	i = 0;
	if (f->precision == 0 && n == 0)
		i += print_x_time(' ', f->width);
	else
		i += width_precision_neg(f, n, c);
	return (i);
}