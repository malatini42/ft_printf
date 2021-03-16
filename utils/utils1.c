/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:03:52 by malatini          #+#    #+#             */
/*   Updated: 2021/03/16 16:28:34 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	if (!c)
		return (0);
	write(1, &c, 1);
	return (1);
}

int	ft_isdigit(int c)
{
	if (!c)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	found_char(const char *str, char c)
{
	int i;

	i = 0;
	if (!c && !str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	is_correct_type(char c)
{
	if (!c)
		return (0);
	if (c == 'i' || c == 'd' || c == 'u' || c == 's' || c == 'c' ||
		c == 'x' || c == 'X' || c == 'p' || c == '%')
	{
		return (1);
	}
	return (0);
}

void	ft_putnbr(unsigned int nbr)//Le calcul est pas top
{
	unsigned int n;

	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

