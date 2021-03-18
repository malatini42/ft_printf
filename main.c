/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:45:36 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 13:46:24 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int main(void)
{

	static char	a01 = 'q';
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;

	ft_printf("Le mien : %-70p\n", &a01);
	printf("Le vrai : %-70p\n", &a01);
	//printf("\n%p\n", &a01);
	//%p%p%p%p%p%p%p%p%p%p%p
	//,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12
	/*
	printf("\n%.p\n", NULL);
	printf("\n%-.p\n", NULL);
	*/
	return (0);
}
