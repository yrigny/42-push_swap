CC	= cc
CFLAGS	= -Wall -Wextra -Werror
TARGET	= push_swap
HEADER	= push_swap.h

SRC		= main.c \
			parser.c \
			sorter.c \
			ft_split.c \
			movements.c \
			utils_1.c \
			utils_2.c \
			utils_3.c \
			ft_printf.c \
			fprinter_1.c \
			fprinter_2.c
OBJ		= $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re:		fclean all

.PHONY:	all clean fclean re
