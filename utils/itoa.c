/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:54:31 by malatini          #+#    #+#             */
/*   Updated: 2021/03/17 18:48:37 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//a renommer 
//a revoir
int		n_size_i(int n)
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

//pas utilisee pour l instant
char	*create_string(char *str, long nb, long length, long sign)
{
	str[length] = '\0';
	while (length > 0)
	{
		str[--length] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign < 0)
		str[length++] = '-';
	return (str);
}

//pas utilise pour l instant
char	*ft_itoa(unsigned int n)
{
	char	*str;
	long	length;
	long	nb;
	long	sign;

	nb = n;
	sign = 1;
	length = (long)n_size_i(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb < 0)
	{
		nb = -nb;
		sign = -sign;
	}
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str = create_string(str, nb, length, sign);
	return (str);
}