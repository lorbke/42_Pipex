# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 13:29:01 by lorbke            #+#    #+#              #
#    Updated: 2022/08/30 17:57:59 by lorbke           ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_handle_error.c ft_pipe_heredoc.c ft_get_paths.c ft_exec_pipe.c
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${PIPEXLIB}
	${CC} ${FLAGS} ${SRC} ${PIPEXLIB} ${LIBFTDIR}/${LIBFTLIB} -o ${NAME}

${PIPEXLIB}: ${OBJ} ${LIBFTDIR}/${LIBFTLIB}
	${AR} ${PIPEXLIB} ${OBJ}

%.o:%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${LIBFTDIR}/${LIBFTLIB}:
	make -C $(LIBFTDIR)

clean:
	${RM} ${OBJ}
	cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME} ${PIPEXLIB}
	cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
