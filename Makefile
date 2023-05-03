# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:10:51 by ftataje-          #+#    #+#              #
#    Updated: 2023/05/03 17:32:41 by ftataje-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SOURCE:.c=.o)

SOURCE = so_long.c	\
		functions/images_mlx.c \
		functions/ord_mlx.c \
		functions/rev_char.c \
		functions/rev.c \
		functions/utils_mls.c \
		functions/utils.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
			
LIBRARY := -framework OpenGL -framework AppKit
MNLBX := miniLIBX/

RED=\033[0;31m
YELLOW=\033[0;33m
END=\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MNLBX) 2> warnigs_total
	mv ./miniLIBX/libmlx.a .
	$(CC) $(CFLAGS) $(OBJS) -L . -lmlx $(LIBRARY) -o $(NAME)

clean:
	make -C $(MNLBX) clean
	$(RM) $(OBJS) warnigs_total libmlx.a
	echo "$(RED)☯ Obj deleted ☯$(END)"


fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)☯ Exec deleted ☯$(END)"

re: fclean all 

.PHONY: all clean fclean re

