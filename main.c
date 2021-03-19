/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 10:12:36 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

//tester pour une tres longue de caracteres
int main(void)
{
	ft_printf("%*s\n", -32, "abc");
	printf("%*s\n", -32, "abc");
	return (0);
}
