/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:56 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 15:52:16 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Modifier la condition au cas où il y aurait des formattages bizzares ?
int		count_total_pc(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count++;
			if (str[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (count);
}

int			found_char_until_type(const char *str, char c)
{
	int i;

	i = 0;
	if (!str && !c)
		return (0);
	while (str[i] && !(is_correct_type(str[i])))
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_putstr_limit(const char *str, int precision)
{
	int i;

	i = 0;
	if (precision > 0)
	{
		while (i < precision)
		{
			if (i >= precision)
				return (i);
			ft_putchar(str[i]);
		i++;
		}
	}
	else
		i = ft_putstr("(null)");
	return (i);
}
