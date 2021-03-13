/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:34:08 by malatini          #+#    #+#             */
/*   Updated: 2021/03/13 16:10:55 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reprendre tous les retours en int pour en faire des ssize_t ?
//On peut aussi faire plusieurs fichiers .h à la fin pour que ce soit + propre
//Remettre le nom des parametres au propre

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define UID 1
# define C 2
# define S 3
# define PC 4
# define H 5
# define P 6

typedef	struct	s_flags
{
	bool justify_left;
	bool zero_pad;
	bool precision;
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
void		ft_putchar(char c);
void		ft_putnbr(int nbr);
int			ft_strlen(const char *s);

int			is_correct_spec(const char *s);//revoir si cette fonction est utilisable?
int			ft_putstr(char *str);
int			find_next_correct_type_no_pc(const char *str);
int			count_total_pc(const char *str);
int			found_star(const char *str);
int			is_after_star(const char *str, char c);
int			handle_star(const char *str, t_format *format, va_list arg_ptr);
//No "pc" pour no %
int			is_correct_type_no_pc(char c);
int			found_char_until_type(const char *str, char c);
int			len_until_end_format(const char *str);
char		c_padding_to_print(t_format *format);

int			diff_width_for_pc(t_format *format);
int			diff_width_for_s(t_format *format, const char *str);
int			diff_width_any_type(t_format *spec, const char *str);
int			print_pad(t_format *spec, const char *str);

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

void		print_s(const char *str, t_format *spec, va_list arg_ptr);

//print_s_utils
int			ft_putstr_precision(char *str, t_format *spec);
int			len_with_precision(const char *str, t_format *spec);

//test

void		printstruct(t_format format);

#endif
