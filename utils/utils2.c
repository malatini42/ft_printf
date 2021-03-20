/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:20:56 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 18:53:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		found_char_until_type(const char *str, char c)
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

int		print_x_time(char c, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

//a re-racourcir
int		len_with_precision(const char *str, t_format *f)
{
	int 	i;
	int 	precision;
	char 	to_print;

	to_print = c_padding_to_print(f);
	if (!str && !f)
		return (0);
	precision = f->precision;
	if (precision == 0 && f->flags.precision == true)
		return (0);
	i = 0;
	if (!str)
		return (0);
	if (f->precision < 0 && f->flags.width == false)
	{
		ft_putstr(str);
		i += ft_strlen(str);
		f->printed_chars += i;
		return (i);
	}
	while (str[i])
	{
		if (i >= precision && precision != 0)
		{
			if (f->precision < 0 && f->width < 0)
			{
				ft_putstr(str);
				i += ft_strlen(str);
				i += print_x_time(to_print, -f->width - ft_strlen(str));
				f->printed_chars += i;
			}
			return (i);
		}
		i++;
	}
	return (i);
}

char	which_x_type(const char *f)
{
	int i;

	if (!f)
		return (0);
	i = 0;
	if (f[i] == '%')
		i++;
	while (!(is_correct_type(f[i])) && f[i])
		i++;
	if (f[i] == 'x')
		return ('x');
	else if (f[i] == 'X')
		return ('X');
	return (0);
}