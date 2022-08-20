# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/08/20 21:07:55 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTDIR = ./libft
LIBFTLIB = libft.a

PIPEXLIB = pipex.a

CC = cc
AR = ar rcs
RM = rm -f
FLAGS = #-Wall -Wextra -Werror

SRC = manage_path.c main.c
OBJ = ${SRC:.c=.o}

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} libft
	@${AR} ${PIPEXLIB} ${OBJ}
	@${CC} ${FLAGS} ${SRC} ${PIPEXLIB} ${LIBFTDIR}/${LIBFTLIB} -o ${NAME}

all: ${NAME}

libft:
	@make -C $(LIBFTDIR)

clean:
	@${RM} ${OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re libft
