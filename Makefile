NAME = philo

HEADER = ./

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

GCC_FLAGS = -Wall -Wextra -Werror -g -pthread

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	@make display
	@echo "Compiling $(NAME)..."
	@$(CC) $(GCC_FLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m"
	@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ "
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗"
	@echo "██████╔╝███████║██║██║     ██║   ██║"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ "
	@echo "\033[0m"
	@make usage

%.o: %.c
	@$(CC) $(GCC_FLAGS) -c -I $(HEADER) ${@:.o=.c} -o $@

clean:
	@echo "Temp files cleaning..."
	@rm -f $(OBJECTS)
	@echo "Temp files cleaning done !\n"

fclean:
	@echo "Cleaning all..."
	@rm -f $(NAME) $(OBJECTS)
	@echo "Cleaning done !\n"

display:
	@echo "^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^\n"

usage:
	@echo "Usage: ./philo <number of philosophers> <time to die> <time to eat> <time to sleep> [number_of_times_each_philosopher_must_eat]\n"

re: fclean all

.PHONY: all clean fclean re display
