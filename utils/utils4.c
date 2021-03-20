/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:22 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 17:51:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_format	*ft_initialize_struct(void)
{
	t_format	*format;

	if (!(format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	format->flags.justify_right = false;
	format->flags.zero_pad = false;
	format->flags.width = false;
	format->flags.precision = false;
	format->flags.star = false;
	format->width = 0;
	format->precision = 0;
	format->type = 0;
	format->printed_chars = 0;
	return (format);
}

bool		justify_right(const char *str, t_format *f)
{
	bool	dash;
	int		max;
	int		len;

	if (!str && !f)
		return (false);
	dash = false;
	max = found_char(str, '-');
	len = len_until_end_format(str);
	if (max && max <= len)
	{
		dash = true;
		f->flags.justify_right = true;
		f->flags.zero_pad = false;
	}
	return (dash);
}

bool		zero_pad(const char *str, t_format *f)
{
	int	i;

	if (!str && !f)
		return (false);
	i = 0;
	if (found_char_until_type(str, '-') != 0)
	{
		f->flags.zero_pad = false;
		f->flags.justify_right = true;
		return (false);
	}
	else
	{
		if (str[1] == '0')
		{
			f->flags.zero_pad = true;
			f->flags.justify_right = false;
			return (true);
		}
	}
	i++;
	return (false);
}

int			fill_type(const char *str, t_format *f)
{
	int	type;

	if (!str && !f)
		return (false);
	type = get_type(str);
	f->type = type;
	return (type);
}

void		fill_struct(const char *str, t_format *f)
{
	if (!str && !f)
		return ;
	fill_type(str, f);
	zero_pad(str, f);
	justify_right(str, f);
	get_width(str, f);
	get_precision(str, f);
}
