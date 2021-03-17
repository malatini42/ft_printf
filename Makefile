# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malatini <malatini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 08:34:15 by malatini          #+#    #+#              #
#    Updated: 2021/03/17 19:47:55 by malatini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main/ft_printf.c \
		./struct/fill_struct_values.c \
		./struct/get_struct_values.c \
		./utils/utils1.c \
		./utils/utils2.c \
		./utils/utils3.c \
		./utils/itoa.c \
		./star/star.c \
		./utils/utils5_print.c \
		./print/print_all.c \
		./type_pc/type_pc.c \
		./type_pc/print_pc_utils.c \
		./type_s/type_s.c \
		./type_s/print_s_utils.c \
		./type_s/print_s_utils2.c \
		./type_s/print_s_utils3_null.c \
		./type_s/print_s_utils4_null.c \
		./type_id/type_id.c \
		./type_id/print_id_utils.c \
		./type_id/print_id_pos.c \
		./type_id/print_id_neg.c \
		./type_u/type_u.c \
		./type_u/print_u_utils.c \
		./type_u/print_u_utils2.c \
		./type_x/type_x.c \
		./type_x/print_x_utils.c \

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: 		${NAME}

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS)

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

test: 		${NAME}
			clear && ${CC} main.c -L. ${NAME} && ./a.out | cat -e

.PHONY:		bonus all clean fclean re
