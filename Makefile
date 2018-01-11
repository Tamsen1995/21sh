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
	src/check_bin_path.c \
	src/error_checks.c \
	src/parser/parser.c \
	src/parser/parser_tree.c \
	src/parser/parser_operator.c \
	src/parser/lexer.c \
	src/builtins/builtin_env.c \
	src/builtins/builtin_exit.c \
	src/builtins/builtin_echo.c \
	src/builtins/builtin_setenv.c \
	src/builtins/builtin_cd.c \
	src/builtins/builtin_unsetenv.c \
	src/builtins/builtins.c \
	src/helpers/check_directory.c \
	src/helpers/putintc.c \
	src/prompt/print_buffer.c \
	src/prompt/prompt_loop.c \
	src/prompt/check_input.c \
	src/prompt/helpers/list_len.c \
	src/prompt/history/add_history.c \
	src/prompt/history/check_hist.c \
	src/prompt/history/check_hist_down.c \
	src/prompt/history/set_cursor_internal.c \
	src/prompt/history/hist_index.c \
	src/prompt/history/replace_buffer.c \
	src/prompt/line_edition/init_cursor.c \
	src/prompt/line_edition/init_line.c \
	src/prompt/line_edition/term_action.c \
	src/prompt/line_edition/get_first_c.c \
	src/prompt/line_edition/free_line_struct.c \
	src/prompt/line_edition/line_buffer/ft_add_buf.c \
	src/prompt/line_edition/line_buffer/get_cur_buffer.c \
	src/prompt/line_edition/line_buffer/stringify_buffer.c \
	src/prompt/line_edition/line_buffer/insert_buffer.c \
	src/prompt/line_edition/line_buffer/ft_new_buf.c \
	src/prompt/line_edition/line_buffer/del_buf_elem.c \
	src/prompt/line_edition/cursor/cursor_movement.c \
	src/prompt/line_edition/cursor/prompt_cursor.c \
	src/prompt/line_edition/cursor/reset_cursor.c \
	src/prompt/line_edition/cursor/set_cursor.c \
	src/test_helpers/print_list_test.c \

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