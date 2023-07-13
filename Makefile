# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madavid <madavid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:16:40 by marine            #+#    #+#              #
#    Updated: 2023/07/13 22:53:54 by madavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	= main.c \
			parsing/parsing.c \
			parsing/lst.c \
			parsing/lst_free.c \
			parsing/split_space.c \
			parsing/heredoc.c \
			exec/exec.c \
			exec/check_cmd.c \
			exec/redirection.c

PREFIX	= srcs

SRCS = $(addprefix ${PREFIX}/, ${SRCS_FILES})

OBJS = $(SRCS:.c=.o)

LIB = -Llibft -lft

INCLUDE	= -Ilibft -Iheader

CC    = cc

FLAGS  = -Wall -Wextra -Werror -g3 #-fsanitize=address 

NAME    = pipex

DEPS			=	${SRCS:.c=.d}

.c.o:
	${CC} ${FLAGS} ${CDFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}

all: ${NAME}

clean:
	${MAKE} -C libft clean
	rm -f ${OBJS}
	rm -f ${DEPS}

fclean: clean
	${MAKE} -C libft fclean
	rm -f ${NAME}

re: fclean all

.PHONY: re fclean all
