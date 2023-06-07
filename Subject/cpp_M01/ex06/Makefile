NAME	:= harlFilter

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
FILES	:= $(wildcard *.cpp)
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
