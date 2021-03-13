/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:55:56 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 15:31:12 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_format	*ft_initialize_struct(void)
{
	t_format *format;

	if (!(format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	format->flags.justify_left = false;
	format->flags.zero_pad = false;
	format->flags.precision = false;
	format->width = 0;
	format->precision  = 0;
	format->type = 0;
	format->printed_chars = 0;
	return (format);
}

bool	justify_left(const char *str, t_format *format)
{
	bool dash;
	int i;

	i = 0;
	dash = false;
	if (found_char(str, '-'))
	{
		dash = true;
		format->flags.justify_left = true;
	}
	i++;
	return (dash);
}

bool	zero_pad(const char *str, t_format *format)
{
	int i;

	i = 0;
	//faire une fonction qui compte la longueur pour ne pas depasser le type
	if (found_char_until_type(str, '-') != 0)
	{
		format->flags.zero_pad = false;
		format->flags.justify_left = true;
		return (false);
	}
	else
	{
		if (str[1] == '0')
		{
			format->flags.zero_pad = true;
			format->flags.justify_left = false;
			return (true);
		}
	}
	i++;
	return (false);
}

int		fill_type(const char *str, t_format *format)
{
	int type;

	type = get_type(str);
	format->type = type;
	return (type);
}

void	fill_struct(const char *str, t_format *format)
{
	fill_type(str, format);
	justify_left(str, format);
	zero_pad(str, format);
	get_width(str, format);
	get_precision(str, format);
}
