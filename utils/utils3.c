/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:53 by malatini          #+#    #+#             */
/*   Updated: 2021/03/29 08:59:24 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		diff_width_any_type(t_format *f, const char *str)
{
	int	diff_width;
	int len;
	int a_width;

	diff_width = 0;
	a_width = f->width > 0 ? f->width : -f->width;
	len = ft_strlen(str);
	if (f->type == S)
	{
		if (str && f->precision >= 0 && f->width > 0)
			diff_width = f->width - len_with_precision(str, f);
		else if (str && f->precision < 0)
			diff_width = a_width - len;
		else if (f->type == S && !str)
			diff_width = f->width - 6;
		else if (f->precision == 0 && f->flags.precision == true)
			diff_width = 0;
		else if (str && f->precision < len && f->flags.precision == true)
			diff_width = a_width - f->precision;
		else
			diff_width = a_width - len;
	}
	else if (f->type == PC)
		diff_width = f->width > 0 ? f->width - 1 : -f->width - 1;
	return (diff_width);
}

int		get_width(const char *str, t_format *f)
{
	int width;
	int i;

	if (!str && !f)
		return (false);
	width = 0;
	i = 1;
	while (str[i] == '-' || str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		width = width * 10 + str[i] - '0';
		i++;
	}
	f->width = width;
	if (width != 0)
		f->flags.width = true;
	return (width);
}

int		get_precision(const char *str, t_format *f)
{
	int		precision;
	int		i;

	precision = 0;
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
		{
			f->flags.precision = true;
			break ;
		}
		if (is_correct_type(str[i]))
			return (precision);
		i++;
	}
	i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		precision = precision * 10 + str[i] - '0';
		i++;
	}
	f->precision = precision;
	return (precision);
}

int		get_type(const char *f)
{
	int i;

	if (!f)
		return (0);
	i = 0;
	if (f[i] == '%')
		i++;
	while (!(is_correct_type(f[i])) && f[i])
		i++;
	if (f[i] == 'i' || f[i] == 'd')
		return (ID);
	else if (f[i] == 'u')
		return (U);
	else if (f[i] == 'c')
		return (C);
	else if (f[i] == 's')
		return (S);
	else if (f[i] == '%')
		return (PC);
	else if (f[i] == 'x' || f[i] == 'X')
		return (H);
	else if (f[i] == 'p')
		return (P);
	return (0);
}

int		count_nbr_u_base(unsigned int nbr, char *base)
{
	long			nb;
	int				temp;
	int				base_len;
	static int		i;

	nb = nbr;
	base_len = 16;
	i = 0;
	if (base_len - 1 < nb)
		count_nbr_u_base(nb / base_len, base);
	temp = base[(int)(nb % base_len)];
	i++;
	return (i);
}
