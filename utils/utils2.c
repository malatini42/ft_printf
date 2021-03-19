/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:38:25 by malatini          #+#    #+#             */
/*   Updated: 2021/03/19 09:39:00 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int is_correct_spec(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '%')
		i++;
	while (s[i])
	{
		if (is_correct_type(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_putstr(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	is_correct_type_no_pc(char c)
{
	if (!c)
		return (0);
	if (c == 'i' || c == 'd' || c == 'u' || c == 's' || c == 'c' ||
		c == 'x' || c == 'X' || c == 'p')
	{
		return (1);
	}
	return (0);
}

//pas logique/pas utilise ?
int find_next_correct_type_no_pc(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (is_correct_type(str[i]))
			return (i);
		i++;
	}
	return (0);
}
