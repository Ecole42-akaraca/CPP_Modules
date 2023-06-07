NAME	:= Violence

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
FILES	:= $(wildcard *.cpp)
OBJ		:= $(FILES:%.c=%.o)
UNAME	:= $(shell uname -s)

ifeq ($(UNAME), Linux)
	LEAK := valgrind -q --leak-check=yes --show-leak-kinds=all ./$(NAME)
else ifeq ($(UNAME), Darwin)
	LEAK := leaks $(NAME)
endif

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

leaks:
	@$(LEAK)

re: fclean all

.PHONY: all clean fclean re leaks
