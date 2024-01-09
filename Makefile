CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

NAME_B	= checker

INC		= push_swap.h

INC_B	= push_swap_bonus.h

SRC		= main.c \
		parser.c \
		sorter.c \
		movements_1.c \
		movements_2.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \

SRC_B	= main_bonus.c \
		parser_bonus.c \
		movements_bonus.c \
		utils_bonus.c

LIB_DIR	= ./libft

LIBFT	= $(LIB_DIR)/libft.a

libft:
	make -C $(LIB_DIR)

$(LIBFT): libft

all: $(LIBFT) $(NAME)

$(NAME): $(INC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L$(LIB_DIR) -lft

bonus: all $(INC_B)
	$(CC) $(CFLAGS) $(SRC_B) -o $(NAME_B) -L$(LIB_DIR) -lft

clean:
	make clean -C $(LIB_DIR)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all

.PHONY:	all bonus libft clean fclean re
