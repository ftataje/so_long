NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := so_long.c functions/*.c
GNL := gnl/*.c
LIBRARY := -framework OpenGL -framework AppKit
MNLBX := miniLIBX/

all: 
	make -C $(MNLBX) 
	$(CC) $(CFLAGS) $(SOURCE) $(GNL) $(LIBRARY) -o $(NAME)

clean:
	make -C $(MNLBX) clean
	$(RM) $(OBJS)
	echo "☯ Obj deleted ☯"


fclean: clean
	$(RM) $(NAME)
	echo "☯ Exec deleted ☯"

re: fclean all 

.PHONY: all clean fclean re

