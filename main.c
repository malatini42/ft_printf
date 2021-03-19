/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 10:57:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

//tester pour une tres longue de caracteres
int main(void)
{
	ft_printf("%.*s", -3, "hello");
	//printf("%.*s", -3, "hello");
	return (0);
}
