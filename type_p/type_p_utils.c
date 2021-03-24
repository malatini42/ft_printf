/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:41:42 by malatini          #+#    #+#             */
/*   Updated: 2021/03/24 18:14:06 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putnbr_p_base(unsigned long long n, char *b)
{
	unsigned long long	nb;
	int					temp;
	int					base_len;
	static int			i;

	nb = n;
	base_len = 16;
	i = 0;
	if ((unsigned long long)(base_len - 1) < nb)
		ft_putnbr_p_base(nb / base_len, b);
	temp = b[(int)(nb % base_len)];
	write(1, &temp, 1);
	i++;
	return (i);
}

int		zero_pad_width_p(t_format *f, unsigned long long p, char c, char *b)
{
	int					i;
	int					len;
	int					w_to_print;
	unsigned long long	ptr;


	i = 0;
	ptr = p;
	//revoir la logique !!! revoir les anciens tests
	//a refaire
	len = count_nbr_u_base(ptr, b) + 2;
	//len = n_size_i(p);
	w_to_print = f->width - len - 2; //- 4
	i += print_x_time(c, w_to_print);
	//Revoir le calcul de la width !!
	i += ft_putstr("0x");
	i += ft_putnbr_p_base(ptr, b);
	return (i);
}
