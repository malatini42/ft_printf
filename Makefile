# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malatini <malatini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 08:34:15 by malatini          #+#    #+#              #
#    Updated: 2021/03/28 11:27:36 by malatini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./ft_printf.c \
		./utils/utils0.c \
		./utils/utils1.c \
		./utils/utils2.c \
		./utils/utils3.c \
		./utils/utils4.c \
		./utils/utils5.c \
		./type_pc/type_pc.c \
		./type_s/type_s.c \
		./type_s/type_s_null.c \
		./type_s/type_s_utils.c \
		./type_id/type_id.c \
		./type_id/type_id_pos.c \
		./type_id/type_id_neg.c \
		./type_id/type_id_neg_utils.c \
		./type_u/type_u.c \
		./type_u/type_u_utils.c \
		./type_u/type_u_utils2.c \
		./type_x/type_x_utils.c \
		./type_x/type_x.c \
		./type_p/type_p.c \
		./type_p/type_p_utils.c \
		./type_c/type_c.c \

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
