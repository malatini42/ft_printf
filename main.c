/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 15:25:17 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

//tester pour une tres longue de caracteres
int main(void)
{
	/*
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	*/
	int		j = -12;
	printf("%i\n", ft_printf("%0.d\n", j));
	printf("%i\n", printf("%0.d\n", j));
	//printf("%.*s\n", -3, "hello");
	return (0);
}
