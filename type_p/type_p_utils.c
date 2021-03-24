/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:41:42 by malatini          #+#    #+#             */
/*   Updated: 2021/03/24 20:52:39 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_p_base(unsigned long long n, char *b)
{
	unsigned long long	nb;
	int					temp;
	int					base_len;

	nb = n;
	base_len = 16;
	if ((unsigned long long)(base_len - 1) < nb)
		ft_putnbr_p_base(nb / base_len, b);
	temp = b[(int)(nb % base_len)];
	write(1, &temp, 1);
}

//pb de calcul de la longueur !!!
int		count_p_length(unsigned long long n, char *b)
{
	int					base_len;
	int i;
	i = 0;
	base_len = 16;
	if ((unsigned long long)(base_len - 1) < n)
		count_p_length(n / base_len, b);
	i++;
	return (i);
}

int		zero_pad_width_p(t_format *f, unsigned long long p, char c, char *b)
{
	int	i;
	int	len;
	int	w_to_print;


	i = 0;
	//revoir la logique !!! revoir les anciens tests
	//a refaire

	len = 9;
	w_to_print = f->width - len; //- 4
	i += print_x_time(c, w_to_print);
	//Revoir le calcul de la width !!
	i += ft_putstr("0x");
	ft_putnbr_p_base(p, b);
	return (i);
}
