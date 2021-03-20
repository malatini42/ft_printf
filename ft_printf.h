/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2021/03/20 20:05:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define ID 1
# define U 2
# define C 3
# define S 4
# define PC 5
# define H 6
# define P 7

typedef	struct	s_flags
{
	bool justify_right;
	bool zero_pad;
	bool precision;
	bool width;
	bool star;
}				t_flags;

typedef struct	s_format
{
	t_flags flags;
	int width;
	int	precision;
	int	type;
	int printed_chars;
}				t_format;

/*
** utils to delete
*/

void		printstruct(t_format format);

/*
** utils0.c 
*/

int			ft_putchar(char c);
int			ft_isdigit(int c);
int			found_char(const char *str, char c);
int			n_size_i(int n);
int			ft_putnbr_i(int nbr);

/*
** utils1.c 
*/

int			is_correct_type(char c);
int			ft_strlen(const char *s);
int			is_correct_spec(const char *s);
int			ft_putstr(const char *str);
char		c_padding_to_print(t_format *format);

/*
** utils2.c 
*/

int			found_char_until_type(const char *str, char c);
char		*ft_strdup(const char *s1);
int			print_x_time(char c, int x);
int			len_with_precision(const char *str, t_format *spec);
char		which_x_type(const char *format);

/*
** utils3.c 
*/

int			diff_width_any_type(t_format *spec, const char *str);
int			get_width(const char *str, t_format *format);
int			get_precision(const char *str, t_format *format);
int			get_type(const char *format);
int			count_nbr_u_base(unsigned int nbr, char *base);

/*
** utils4.c 
*/

t_format	*ft_initialize_struct(void);
bool		justify_right(const char *str, t_format *format);
bool		zero_pad(const char *str, t_format *format);
int			fill_type(const char *str, t_format *format);
void		fill_struct(const char *str, t_format *format);

/*
** utils5.c 
*/

int			found_star(const char *str, t_format *format);
int			after_star(const char *str, char c);
int			handle_star(const char *str, t_format *f, va_list arg_ptr, int star);


/*
** type_x.c 
*/

int		width_precision_pos_x(t_format *f, unsigned int n, char p, char *b);
int		zero_pad_precision_x(t_format *f, unsigned int n, char p, char *b);
int		pos_x_justify(t_format *f, unsigned int number, char x);
int		pos_x_no_justify(t_format *f, unsigned int number, char x);
void	print_x(const char *str, t_format *format, va_list arg_ptr);

/*
** type_x_utils.c 
*/

int		r_width_precision_pos_x(t_format *f, int n, char p, char *b);
int		zero_pad_width_x(t_format *f, unsigned int n, char p, char *b);
int		handle_null_pointer(t_format *f, unsigned long long p);

/*
** type_u.c 
*/

int		width_precision_u(t_format *f, unsigned int n, char c);
int 	u_no_justify(t_format *f, unsigned int n);
int 	u_justify(t_format *f, unsigned int n, char c);
int		u_number(t_format *f, unsigned int n);
void	print_u(t_format *f, va_list arg);

/*
** type_u_utils.c 
*/

int		r_width_precision_u(t_format *f, int n, char c);
int		zero_pad_precision_u(t_format *f, unsigned int n, char print);
int		n_size_u(unsigned int n);
void	ft_putnbr_u(unsigned int nbr);
int		ft_putnbr_u_base(unsigned int n, char *base);

/*
** type_s.c 
*/

int		print_pad_s(t_format *f, const char *str);
void	print_null_s(t_format *f);
void	print_s(t_format *f, va_list arg);

/*
** type_s_utils.c 
*/

int		ft_putstr_precision(char *str, t_format *f);
int		ft_putstr_limit(const char *s, int preci, int w, char c);
int		ft_put_pad_0_precision(t_format *f);
int		zero_pad_width(t_format *f, int n, char c);
int		len_until_end_format(const char *s);

/*
** type_s_null.c 
*/

int		null_s_width_no_justify(t_format *f, int precision);
int		null_s_no_justify(t_format *f, char c);
int		width_precision_null_left(t_format *f);
int		null_s_justify(t_format *f);

/*
** type_pc.c 
*/

int		count_total_pc(const char *str);
int		print_pad_pc(t_format *f, const char *str);
void	print_pc(const char *str, t_format *f);

/*
** type_p.c 
*/

int		ft_putnbr_p_base(unsigned long long nbr, char *base);
int		print_zero_pad_then_number_width_p(t_format *f, unsigned long long ptr, char c, char *b);
int		print_zero_pad_then_number_precision_p(t_format *f, unsigned long long ptr, char c, char *b);
int		print_width_and_precision_pos_p(t_format *f, unsigned long long ptr, char c, char *b);
int 	print_pos_p_no_justify(t_format *f, unsigned long long ptr);
//int		print_pos_p_number(t_format *f, unsigned long long ptr);
void	print_p(const char *str, t_format *f, va_list arg);

/*
** type_id.c 
*/

int		print_pad_then_number(t_format *f, int n);
int		print_zero_pad_then_number_width(t_format *f, int n, char c);
int		print_zero_pad_then_number_precision_i(t_format *f, int n, char c);
int		print_zero_pad_true_width(int n, char c, int w_to_print);
void	print_id(t_format *f, va_list arg);

/*
** type_id_utils.c 
*/

int		print_pad_then_number(t_format *f, int n);
int		print_zero_pad_then_number_precision_i(t_format *f, int n, char c);
int		print_zero_pad_true_width(int n, char c, int w_to_print);

/*
** type_id_pos.c 
*/

int		print_width_and_precision_pos(t_format *f, int n, char c);
int		reverse_print_width_and_precision_pos(t_format *f, int n, char c);
int 	print_pos_no_justify(t_format *f, int n);
int 	print_pos_justify(t_format *f, int n, char c);
int		print_pos_number(t_format *f, int n);

/*
** type_id_neg.c 
*/

int		print_width_and_precision_neg(t_format *f, int n, char c);
int		reverse_print_width_and_precision_neg(t_format *f, int n, char p);
int 	print_neg_no_justify(t_format *f, int n, char c);
int 	print_neg_justify(t_format *f, int n, char c);
int		print_neg_number(t_format *f, int n);

/*
** type_c.c 
*/

int		print_null_c(t_format *f);
int		print_c_no_justify(t_format *f, char c);
int		print_c_justify(t_format *f, char c);
void	print_c(t_format *f, va_list arg);

int		ft_printf(const char *format, ...);

#endif
