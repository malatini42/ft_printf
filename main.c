/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/25 09:11:04 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int main(void)
{
	static char	a01;
	int		a = 12;
	int		b = 18;
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

	//printf("%i\n", count_p_length(-1, "0123456789abcdef"));
/*
	printf("Le mien : %i\n", ft_printf("%-00000-----*i",18, 8));
	printf("Le vrai : %i\n", printf("%-00000-----*i", 18, 8));
*/

	printf("Le mien : %i\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d",  a, i, a, i, a, i, a, i, a, i));
	printf("Le vrai : %i\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d",  a, i, a, i, a, i, a, i, a, i));

/*
	printf("Le mien : %i\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x",  a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	printf("Le vrai : %i\n", printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x",  a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
*/

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
