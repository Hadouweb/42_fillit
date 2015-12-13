CC = gcc -Wall -Werror -Wextra

SRC_PATH = ./srcs

HEADER = -I./includes -I./libft

DEP = $(HEADER) -L./libft -lft

SRC = 	$(SRC_PATH)/ft_algo.c\
		$(SRC_PATH)/ft_check_algo.c\
		$(SRC_PATH)/ft_debug.c\
		$(SRC_PATH)/ft_list.c\
		$(SRC_PATH)/ft_memory.c\
		$(SRC_PATH)/ft_read.c\
		$(SRC_PATH)/fillit.c\
		$(SRC_PATH)/ft_heuristic.c\
		$(SRC_PATH)/ft_check_read.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR=libft

LIBFT=$(HELLO_DIR)/libft.a

NAME = fillit

all: $(LIBFT) $(NAME)
 
$(NAME): $(OBJ)
	@$(CC) $(DEP) -o $(NAME) $(OBJ)
	@echo " Fillit done.\033[0;02m"

$(LIBFT):
	@(cd $(LIBFT_DIR) && $(MAKE))

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[1;32m.\c"

clean:
	@rm -f $(OBJ)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean: clean
	@rm -f $(NAME)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

re: fclean all

.PHONY: all clean fclean re
