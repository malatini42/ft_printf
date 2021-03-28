/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:59:50 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 16:41:19 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	printf("\n%i\n", ft_printf("%-9.10x", UINT_MAX));
	printf("\n%i\n", printf("%-9.10x", UINT_MAX));
	return (0);
}