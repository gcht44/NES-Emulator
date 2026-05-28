NAME = NES-Emu

CC = cc
CFLAGS = -Werror -Wall -Wextra -g

INCLUDE = -I./includes

SRCS = main.c addressing_mode.c rom.c bus.c cpu.c ram.c stack.c blaarg.c opcode.c opcode_table.c
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