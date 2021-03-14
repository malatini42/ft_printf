/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:56 by malatini          #+#    #+#             */
/*   Updated: 2021/03/14 11:33:20 by malatini         ###   ########.fr       */
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
	while (str[i] && !(is_correct_type(str[i])))
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}
