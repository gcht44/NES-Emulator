NAME = NES-Emu

CC = cc
CFLAGS = -Werror -Wall -Wextra

INCLUDE = -I./includes

SRCS = main.c rom.c bus.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@echo Clean all obj dir
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Delete binary $(NAME)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re