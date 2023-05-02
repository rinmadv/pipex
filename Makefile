# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madavid <madavid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:16:40 by marine            #+#    #+#              #
#    Updated: 2023/05/02 19:42:37 by madavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCDIR = srcs
BONUSDIR = bonus
INCDIR = -Iheader -Ilibft

# Compilation options
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 $(INCDIR)

# Files
EXEC = pipex
FILES = main.c \
		parsing.c \
		parse.c \
		split_space.c \
		exec.c

LIBPATH = -Llibft

LIBFT = libft/libft.a

SRCS = $(addprefix srcs/,$(FILES))

OBJS = $(SRCS:.c=.o)

DEPENDS = ${SRCS:.c=.d}

# Rules
all: $(EXEC)

$(EXEC): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBPATH) -o $(EXEC)

$(LIBFT):
	make -C libft

-include $(DEPENDS)

clean:
	rm -rf $(OBJS)
	rm -f ${DEPS}
	make -C libft clean
	
fclean: clean
	rm -f $(EXEC)
	make -C libft fclean
	
re: fclean all

.PHONY: all clean fclean re libft