NAME=push_swap
FLAGS=-Wall -Wextra -Werror -I includes/
LIBFT=libft.a
LIBFLAGS=-lft -L libft/
SRCSF=errors_handling.c do_ops.c do_ops2.c second_sort.c\
	  ops.c debug_fcts.c main.c pile_tools.c first_sort.c pile_tools2.c \
	  check_complexity.c easy_pile.c pile_tools3.c
OBJSF=$(SRCSF:.c=.o)
SRCDIR=srcs/
OBJDIR=objs/
SRCS=$(addprefix srcs/, $(SRCSF))
OBJS=$(addprefix objs/, $(OBJSF))

all: $(LIBFT) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo " \c"
	@gcc $(FLAGS) -c $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "\033[1;35mpush_swap compiling... |\033[0m\033[45m\c"

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\033[0m\033[1;35m|\033[0m"
	@mv $(OBJSF) $(OBJDIR)
	@gcc $(LIBFLAGS) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;32mpush_swap ready ✓\033[0m"

clean:
	@rm -rf objs/
	@echo "\033[1;31mpush_swap objects deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31mpush_swap binary file deleted\033[0m"
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
