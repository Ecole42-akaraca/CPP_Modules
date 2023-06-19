NAME	:= PmergeMe

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
FILES	:= $(wildcard *.cpp)
OBJ		:= $(FILES:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

random:
	@echo "$(RED) ##$(GREEN) Size: $(INPUT) $(RED)## $(GREEN) Random number generated... $(NC)\n"
	@ARG=$$(ruby -e "puts (1..1000000).to_a.shuffle[1..$(INPUT)].join(' ')"); ./PmergeMe $${ARG}

.PHONY: all clean fclean re random
