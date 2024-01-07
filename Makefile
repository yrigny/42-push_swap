CC	= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

NAME_B	= checker

HEADER	= push_swap.h

SRC	= main.c \
		parser.c \
		sorter.c \
		movements_1.c \
		movements_2.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \

SRC_B	= 

LIB_DIR	= ./libft

LIBFT	= $(LIB_DIR)/libft.a

libft:
	$(MAKE) -C $(LIB_DIR)

$(LIBFT): libft

all: $(LIBFT) $(NAME)

$(NAME): $(SRC) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L$(LIB_DIR) -lft

bonus: all
	$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B) -L$(LIB_DIR) -lft

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY:	all bonus libft clean fclean re
