/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:55:56 by malatini          #+#    #+#             */
/*   Updated: 2021/03/15 09:59:01 by malatini         ###   ########.fr       */
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
	format->flags.width = false;
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
	int max;
	int len;

	if (!str && !format)
		return (false);
	dash = false;
	max = found_char(str, '-');
	len = len_until_end_format(str);
	//printf("\n%i\n", len);
	if (max && max <= len)
	{
		dash = true;
		format->flags.justify_left = true;
	}
	return (dash);
}

bool	zero_pad(const char *str, t_format *format)
{
	int i;

	if (!str && !format)
		return (false);
	i = 0;
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

	if (!str && !format)
		return (false);
	type = get_type(str);
	format->type = type;
	return (type);
}

void	fill_struct(const char *str, t_format *format)
{
	if (!str && !format)
		return ;
	fill_type(str, format);
	justify_left(str, format);
	zero_pad(str, format);
	get_width(str, format);
	get_precision(str, format);
}
