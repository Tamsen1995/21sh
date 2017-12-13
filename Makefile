CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = 21sh
SRC = src/main.c \
	src/get_next_line.c \
	src/sh_execute.c \
	src/sh_launch.c \
	src/sh_path_var.c \
	src/init_env.c \
	src/init_shell.c \
	src/check_bin_cmd.c \
	src/free_shell.c \
	src/store_commands.c \
	src/builtins/builtin_env.c \
	src/builtins/builtin_exit.c \
	src/builtins/builtin_echo.c \
	src/builtins/builtin_setenv.c \
	src/builtins/builtin_cd.c \
	src/builtins/builtin_unsetenv.c \
	src/builtins/builtins.c \
	src/helpers/check_directory.c \
	src/helpers/putintc.c \
	src/helpers/print_list.c \
	src/prompt/prompt_loop.c \
	src/check_bin_path.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT) -ltermcap

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all