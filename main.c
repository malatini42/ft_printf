/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/21 10:25:03 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	//printf("%i\n", ft_printf("%.0i\n", -12345678));
	printf("%i\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d));
	printf("%i\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d));
	//printf("%i\n", printf("%0.i\n", -12345678));
	//printf("%.*s\n", -3, "hello");
	return (0);
}
