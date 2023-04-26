NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders

RM := /bin/rm -rf
OBJS := $(SOURCE:.c=.o)

SOURCE := functions/*.c
GNL := gnl/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MNLBX := miniLIBX/

BLACK=\033[0;30m
RED=\033[0;31m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

all:
	$(MAKE) -C $(MNLBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GNL) $(LIBRARY) -o $(NAME)

clean:
	$(MAKE) -C $(MNLBX) clean
	$(RM) $(OBJS)
	echo "$(RED)☯ Obj deleted ☯$(END)"


fclean: clean
	$(RM) $(NAME)
	echo "$(MAG)☯ Exec deleted ☯$(END)"

re: fclean all 

.PHONY: all clean fclean re

