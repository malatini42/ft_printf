/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:16:15 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 07:59:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	//int		a = -2;
	int		b = 4;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	//int		i = 8;
	//int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	//char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	//char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	
	//char s[3] = "0";
	char a = 'a';
	char *p = NULL;
	int i = 42;
	int j = -42;
	printf("Le mien : %i\n", ft_printf("%-*.*u\n", 0, - 1, 0));
	printf("Le vrai : %i\n", printf("%-*.*u\n", 0, -1, 0));
	return (0);
}
