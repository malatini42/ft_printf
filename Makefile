# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malatini <malatini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 08:34:15 by malatini          #+#    #+#              #
#    Updated: 2021/03/14 10:43:35 by malatini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main/ft_printf.c \
		./struct/fill_struct_values.c \
		./struct/get_struct_values.c \
		./utils/utils1.c \
		./utils/utils2.c \
		./utils/utils3.c \
		./star/star.c \
		./utils/utils5_len.c \
		./print/print_all.c \
		./type_pc/type_pc.c \
		./type_s/type_s.c \
		./type_s/print_s_utils.c \

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
