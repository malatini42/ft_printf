/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2021/03/28 17:02:41 by malatini         ###   ########.fr       */
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
# include <limits.h>

# define ID 1
# define U 2
# define C 3
# define S 4
# define PC 5
# define H 6
# define P 7

typedef	struct	s_flags
{
	bool		justify_right;
	bool		zero_pad;
	bool		precision;
	bool		width;
	bool		star;
}				t_flags;

typedef struct	s_format
{
	t_flags		flags;
	int			width;
	int			precision;
	int			type;
	int			printed_chars;
}				t_format;

int				ft_putchar(int c);
int				ft_isdigit(int c);
int				found_char(const char *str, char c);
int				n_size_i(int n);
int				ft_putnbr_i(int nbr);
int				is_correct_type(char c);
int				ft_strlen(const char *s);
int				is_correct_spec(const char *s);
int				ft_putstr(const char *str);
char			c_padding_to_print(t_format *format);
int				found_char_until_type(const char *str, char c);
char			*ft_strdup(const char *s1);
int				print_x_time(char c, int x);
int				len_with_precision(const char *str, t_format *spec);
char			which_x_type(const char *format);
int				diff_width_any_type(t_format *spec, const char *str);
int				get_width(const char *str, t_format *format);
int				get_precision(const char *str, t_format *format);
int				get_type(const char *format);
int				count_nbr_u_base(unsigned int nbr, char *base);
t_format		*ft_initialize_struct(void);
bool			justify_right(const char *str, t_format *format);
bool			zero_pad(const char *str, t_format *format);
int				fill_type(const char *str, t_format *format);
void			fill_struct(const char *str, t_format *format);
int				found_star(const char *str, t_format *format);
int				after_star(const char *str, char c);
int				handle_star(const char *str, t_format *f, va_list arg_ptr,
					int star);
int				calculate_width(t_format *f, int n, int p_to_print);
int				width_precision_pos_x(t_format *f, unsigned int n, char p,
					char *b);
int				zero_pad_precision_x(t_format *f, unsigned int n, char p,
					char *b);
int				pos_x_justify(t_format *f, unsigned int number, char x);
int				pos_x_no_justify(t_format *f, unsigned int number, char x);
void			print_x(const char *str, t_format *format, va_list arg_ptr);
int				r_width_precision_pos_x(t_format *f, unsigned int n, char p,
					char *b);
int				zero_pad_width_x(t_format *f, unsigned int n, char p, char *b);
int				handle_null_pointer(t_format *f, unsigned long long p);
int				calculate_w_p(t_format *f, int pre, unsigned int n, char *b);
int				width_precision_u(t_format *f, unsigned int n);
int				u_no_justify(t_format *f, unsigned int n);
int				u_justify(t_format *f, unsigned int n, char c);
int				u_number(t_format *f, unsigned int n);
void			print_u(t_format *f, va_list arg);
int				handle_true_width(t_format *f, int n, int w_to_print, int i);
int				calculate_width_u(t_format *f, unsigned int n, int p_to_print);
int				calculate_w_u_r(t_format *f, unsigned int n, int s, int p);
int				handle_neg_w_p_u(t_format *f, unsigned int n, int s, int i);
int				handle_n0_w_p_r(t_format *f, unsigned int n, int i);
int				r_width_precision_u(t_format *f, unsigned int n, char c);
int				zero_pad_precision_u(t_format *f, unsigned int n, char print);
int				n_size_u(unsigned int n);
int				ft_putnbr_u(unsigned int nbr);
int				ft_putnbr_u_base(t_format *f, unsigned int n, char *base);
int				handle_negs_ux(t_format *f, unsigned int n, char *base, int w);
int				print_pad_s(t_format *f, const char *str);
void			print_null_s(t_format *f);
void			print_s(t_format *f, va_list arg);
int				ft_putstr_precision(char *str, t_format *f);
int				ft_putstr_neg_precision(char *str);
int				ft_putstr_limit(const char *s, int preci, int w, t_format *f);
int				ft_put_pad_0_precision(t_format *f);
int				len_until_end_format(const char *s);
int				null_s_width_no_justify(t_format *f, int precision);
int				null_s_no_justify(t_format *f);
int				width_precision_null_left(t_format *f);
int				null_s_justify(t_format *f);
int				count_total_pc(const char *str);
int				print_pad_pc(t_format *f, const char
					*str);
void			print_pc(const char *str, t_format *f);
int				zero_pad_precision_p(t_format *f, unsigned long long ptr,
					char c, char *b);
int				width_precision_p_p(t_format *f, unsigned long long ptr, char c,
					char *b);
int				pos_p_no_justify(t_format *f, unsigned long long ptr);
int				pos_p_justify(t_format *f, unsigned long long p, char *b);
void			print_p(const char *str, t_format *f, va_list arg);
void			ft_putnbr_p_base(unsigned long long n, char *b);
int				zero_pad_width_p(t_format *f, unsigned long long ptr, char c,
					char *b);
int				count_p_length(unsigned long long n, char *b);
int				r_width_precision_p(t_format *f, unsigned long long p, char c,
					char *b);
int				handle_special_maxs(t_format *f, unsigned int n, int i);
int				zero_pad_width(t_format *f, unsigned int n, char c);
int				zero_pad_precision_i(t_format *f, int n, char c);
void			print_id(t_format *f, va_list arg);
int				print_pad_then_number(t_format *f, int n);
int				zero_pad_true_width(int n, char c, int w_to_print);
int				width_precision_pos(t_format *f, int n, char c);
int				r_width_precision_pos(t_format *f, int n, char c);
int				pos_no_justify(t_format *f, int n);
int				pos_justify(t_format *f, int n, char c);
int				pos_number(t_format *f, int n);
int				width_precision_neg(t_format *f, int n, char c);
int				r_print_width_precision_neg(t_format *f, int n, char p);
int				neg_no_justify(t_format *f, int n, char c);
int				neg_justify(t_format *f, int n, char c);
int				neg_number(t_format *f, int n);
int				width_precision_neg_no_justify(t_format *f, int n, char c);
int				precision_neg_justify(t_format *f, int n);
int				precision_neg_justify_specials(t_format *f, int n,
					int p_to_print);
int				calculate_width_neg(t_format *f, int n);
int				print_null_c(t_format *f);
int				print_c_no_justify(t_format *f, int c);
int				print_c_justify(t_format *f, int c);
void			print_c(t_format *f, va_list arg);
int				ft_printf(const char *format, ...);

#endif
