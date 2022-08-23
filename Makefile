# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:29:01 by doreshev          #+#    #+#              #
#    Updated: 2022/08/23 18:37:01 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFTDIR = ./libft
LIBFTLIB = libft.a

PIPEXLIB = pipex.a

CC = cc
AR = ar rcs
RM = rm -f
INCLUDES = -g -fsanitize=address,undefined
FLAGS = #-Wall -Wextra -Werror

SRC = main.c ft_get_paths.c ft_execute.c ft_write_to_file_fd.c
OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} libft
	${AR} ${PIPEXLIB} ${OBJ}
	${CC} ${FLAGS} ${SRC} ${PIPEXLIB} ${LIBFTDIR}/${LIBFTLIB} -o ${NAME}

all: ${NAME}

libft:
	make -C $(LIBFTDIR)

clean:
	${RM} ${OBJ}
	cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re libft
