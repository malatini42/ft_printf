/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/24 14:23:03 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int main(void)
{
	int		a = -1;
	int		b = 1;
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

/*
	printf("Le mien : %i\n", ft_printf("%-*.*s\n", -7, -3, "yolo"));
	printf("Le vrai : %i\n", printf("%-*.*s\n", -7, -3, "yolo"));
*/

	printf("Le mien : %i\n", ft_printf("%*.*u\n", a, b, -12));
	printf("Le vrai : %i\n", printf("%*.*u\n", a, b, -12));

/*
	printf("Le mien : %i\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	printf("Le vrai : %i\n", printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
*/
	//printf("%i\n", ft_printf("%.0i\n", -12345678));
	//ft_putnbr_i(0);
	/*
	while (a < 5)
	{

		a++;
	}
	*/
	//printf("%i\n", printf("%0.i\n", -12345678));
	//printf("%.*s\n", -3, "hello");
	return (0);
}
