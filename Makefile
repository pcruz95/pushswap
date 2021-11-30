NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libraries/libft/
INCLUDES = ./includes

SRC = ./source/

FILES = $(SRC)push_swap.c $(SRC)operations.c $(SRC)sort.c $(SRC)sort_aux.c $(SRC)quick_sort.c $(SRC)system.c $(SRC)choose_rotation.c $(SRC)init.c $(SRC)init_stack_a.c $(SRC)send_to_b.c $(SRC)return_to_a.c $(SRC)reduce_instructions.c $(SRC)small_sort.c $(SRC)return_to_a_sorting.c
OBJECTS = push_swap.o operations.o sort.o sort_aux.o quick_sort.o system.o choose_rotation.o init.o init_stack_a.o send_to_b.o return_to_a.o reduce_instructions.o small_sort.o return_to_a_sorting.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
