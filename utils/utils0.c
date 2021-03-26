/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:03:52 by malatini          #+#    #+#             */
/*   Updated: 2021/03/26 10:26:48 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
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
	int len;

	i = 0;
	len = len_until_end_format(str);
	if (!c && !str)
		return (0);
	while (str[i] && i < len)
	{
		if (str[i] == c && str[i] && i < len)
			return (i);
		i++;
	}
	return (0);
}

int	n_size_i(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_i(int nbr)
{
	int n;
	int i;

	i = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		ft_putchar('-');
		i++;
	}
	if (n > 9)
		i += ft_putnbr_i(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}
