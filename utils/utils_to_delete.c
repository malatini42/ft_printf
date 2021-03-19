/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:58:52 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 17:45:27 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//A suppimer, test purposes
void	printstruct(t_format format)
{
	printf("Justify-left : %d\n", format.flags.justify_right);
	printf("Zero-pad : %d\n", format.flags.zero_pad);
	printf("Width : %d\n", format.width);
	printf("Width bool : %d\n", format.flags.width);
	printf("Precision bool : %d\n", format.flags.precision);
	printf("Precision: %d\n", format.precision);
	printf("Type : %d\n", format.type);
}
