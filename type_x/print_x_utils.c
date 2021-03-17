/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:45:38 by malatini          #+#    #+#             */
/*   Updated: 2021/03/17 19:46:02 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	which_x_type(const char *format)
{
	int i;

	if (!format)
		return (0);
	i = 0;
	if (format[i] == '%')
		i++;
	while (!(is_correct_type(format[i])) && format[i])
		i++;
	if (format[i] == 'x')
		return ('x');
	else if (format[i] == 'X')
		return ('X');
	return (0);
}

//a revoir
void	ft_putnbr_u_base(unsigned int nbr, char *base, int base_len)
{
	long	nb;
	int		temp;

	nb = nbr;
	if (nb >= base_len)
		ft_putnbr_u_base(nb / base_len, base, base_len);
	temp = base[(unsigned int)(nb % 16)];
	write(1, &temp, 1);
}
