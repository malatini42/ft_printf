/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2021/03/18 09:57:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reprendre tous les retours en int pour en faire des ssize_t ?
//On peut aussi faire plusieurs fichiers .h à la fin pour que ce soit + propre
//Remettre le nom des parametres au propre, ne pas mettre toutes les fonctions
//je crois que j ai confondu la droite et la gauche ! a changer "justify right"

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
	bool justify_left;
	bool zero_pad;
	bool precision;
	bool width;
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
** UTILS - a mettre séparément plus tard
*/

int			found_char(const char *str, char c);
int			is_correct_type(char c);
int			ft_isdigit(int c);
int			ft_putchar(char c);
void		ft_putnbr_i(int nbr);
int			ft_strlen(const char *s);

int			is_correct_spec(const char *s);//revoir si cette fonction est utilisable?
int			ft_putstr(const char *str);
int			find_next_correct_type_no_pc(const char *str);
int			count_total_pc(const char *str);
int			found_star(const char *str);
int			is_after_star(const char *str, char c);
int			handle_star(const char *str, t_format *format, va_list arg_ptr);
char		*ft_strcpy(char *dst, const char *src);
//No "pc" pour no %
int			is_correct_type_no_pc(char c);
int			found_char_until_type(const char *str, char c);
int			len_until_end_format(const char *str);
char		c_padding_to_print(t_format *format);

int			diff_width_for_pc(t_format *format);
int			diff_width_for_s(t_format *format, const char *str);
int			diff_width_any_type(t_format *spec, const char *str);
int			print_pad_pc(t_format *spec, const char *str);
char		*ft_strdup_until_type(const char *s1);
int			ft_putstr_limit(const char *str, int precision, int witdh, char to_print);
//bool		justify_left_s(const char *str, t_format *format);
char		*ft_strdup(const char *s1);
int			ft_put_pad_0_precision(t_format *format);
int			print_pad_null_s_justify_left(t_format *spec);
int			print_x_time(char c, int x);
char		which_x_type(const char *format);
//int			ft_putstr_width(const char *str, int width);

/*
** ft_printf.c
*/

int			ft_printf(const char *format, ...);
int			parse(const char *format, va_list arg_ptr);
/*
** struct.c
*/

t_format	*ft_initialize_struct(void);

/*
** get_struct_values.c - a revoir
*/

int			get_width(const char *str, t_format *format);
int			get_precision(const char *str, t_format *format);
int			get_type(const char *format);
void		print_type(const char *str, t_format *spec, va_list arg_ptr);

/*
** fill_struct.c
*/

bool		justify_left(const char *str, t_format *format);
bool		zero_pad(const char *str, t_format *format);
int			fill_width(const char *str, t_format *format);
int			fill_precision(const char *str, t_format *format);
int			fill_type(const char *str, t_format *format);
void		fill_struct(const char *str, t_format *format);

/*
** manage_type.c a revoir (autres fonctions dans fichiers separes)
*/
//type_pc

void		print_pc( const char *str, t_format *spec);

//type_s

void		print_s(t_format *format, va_list arg_ptr);
int			print_pad_s(t_format *spec, const char *str);
int			print_pad_null_s_no_left(t_format *spec, int max_precision);
void		print_null_s(t_format *format);
int			redirect_no_justify_left(t_format *format, char print);

//print_s_utils
int			ft_putstr_precision(char *str, t_format *spec);
int			len_with_precision(const char *str, t_format *spec);
int			width_precision_null_left(t_format *format);

//type_id

void		print_id(t_format *format, va_list arg_ptr);

//itoa - remettre au propre
int			n_size_i(int n);
char		*create_string(char *str, long nb, long length, long sign);
char		*ft_itoa(int n);

int			print_pos_number(t_format *format, int number);
int 		print_pos_no_justify(t_format *format, int number);
int 		print_pos_justify(t_format *format, int number, char print);

int			print_neg_number(t_format *format, int number);
int 		print_neg_no_justify(t_format *format, int number, char print);
int 		print_neg_justify(t_format *format, int number, char print);

//print_id utils

int			print_pad_then_number(t_format *format, int number);
int			print_zero_pad_then_number_width(t_format *format, int number, char print);
int			print_zero_pad_then_number_precision_i(t_format *format, int number, char print);
int			print_zero_pad_true_width(int number, char print, int w_to_print);
int			print_width_and_precision_pos(t_format *format, int number, char print);
int			print_width_and_precision_neg(t_format *format, int number, char print);
int			reverse_print_width_and_precision_neg(t_format *format, int number, char print);
int			reverse_print_width_and_precision_pos(t_format *format, int number, char print);
//test

//type-u

void	print_u(t_format *format, va_list arg_ptr);

void		printstruct(t_format format);
//a revoir
int		n_size_u(unsigned int n);
void	ft_putnbr_u(unsigned int nbr);
int		print_pos_u_number(t_format *format, unsigned int number);
int 	print_pos_u_justify(t_format *format, unsigned int number, char print);
int 	print_pos_u_no_justify(t_format *format, unsigned int number);
int		print_zero_pad_then_number_precision_u(t_format * format, unsigned int number, char char_to_print);
int		print_width_and_precision_pos_u(t_format *format, unsigned int number, char print);
int		reverse_print_width_and_precision_pos_u(t_format *format, int number, char print);
int 	print_pos_u_justify(t_format *format, unsigned int number, char print);
//int		print_zero_pad_then_number_width_u(t_format *format, unsigned int number, char print);
//a faire
//int print_pos_u_number(format, number);

//type x
void		print_x(const char *str, t_format *format, va_list arg_ptr);
int			ft_putnbr_u_base(unsigned int nbr, char *base);
int 		print_pos_x_no_justify(t_format *format, unsigned int number, char x);
int			print_zero_pad_then_number_width_x(t_format *format, unsigned int number, char print, char *base);
int			count_nbr_u_base(unsigned int nbr, char *base);
int 		print_pos_x_justify(t_format *format, unsigned int number, char x);
int			print_zero_pad_then_number_precision_x(t_format * format, unsigned int number, char print, char *base);
//+ faire un putnbr_u

#endif
