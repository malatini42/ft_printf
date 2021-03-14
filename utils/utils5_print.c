/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:58:52 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 13:56:19 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A suppimer, test purposes
void	printstruct(t_format format)
{
	printf("Justify-left : %d\n", format.flags.justify_left);
	printf("Zero-pad : %d\n", format.flags.zero_pad);
	printf("Width : %d\n", format.width);
	printf("Precision: %d\n", format.precision);
	printf("Type : %d\n", format.type);
}
