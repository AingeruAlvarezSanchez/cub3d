#SHELL = /bin/bash
NAME = cub3D

# COMPILATION RELATED VARIABLES #
CC = clang
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
SANITIZE = -fsanitize=address
#################################

### INCLUDE RELATED VARIABLES ###
LIBFT = include/Libft_extended/
MINILIB = include/minilib/
FRAMEWORK = -Lmlx -lmlx -framework OpenGL -framework AppKit
#################################

#### FILES RELATED VARIABLES ####
INCLUDE = -I include/
FILES = srcs/cubed.c					\
		srcs/errors.c					\
		srcs/map_initial_errors.c		\
		srcs/create_map.c				\
		srcs/textures_initial_errors.c	\
		srcs/color_initial_errors.c		\
		srcs/utils.c					\
		srcs/get_next_line.c			\
		srcs/color_resolution_init.c	\
		srcs/draw.c						\
		srcs/hangman.c					\
		srcs/keys.c						\
		srcs/spellcaster.c				\
		srcs/thundercaster.c			\
		srcs/thundercaster_init.c		\
		srcs/thundercaster_move.c		\
		srcs/thundercaster_utils.c		\

OBJS = $(FILES:%.c=%.o)
#################################

#### COLOR RELATED VARIABLES ####
RED = \033[0;91m
RR = \033[0;31m
BLACK = \033[0;90m
GREEN = \033[0;32m
BLUE = \033[0;34m
WHITE = \033[1;37m
END = \033[0;0m
define WELCOME_TO_HELL1
     $(END)█     █░▓█████  ██▓     ▄████▄   ▒█████   ███▄ ▄███▓▓█████    ▄▄▄█████▓ ▒█████      ██░ ██ ▓█████  ██▓     ██▓
    ▓█░ █ ░█░▓█   ▀ ▓██▒    ▒██▀ ▀█  ▒██▒  ██▒▓██▒▀█▀ ██▒▓█   ▀    $(RR)▓$(WHITE)  ██▒ $(RR)▓▒$(WHITE)▒██▒  ██▒   ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒
endef
define WELCOME_TO_HELL2
    $(WHITE)▒█░ █ ░█ ▒███   ▒██░    ▒▓█    ▄ ▒██░  ██▒▓██    ▓██░▒███      $(RR)▒$(WHITE) ▓██░ $(RED)▒$(WHITE)░▒██░  ██▒   ▒██▀▀██░▒███   ▒██░    ▒██░
    ░█░ █ ░█ ▒▓█  ▄ ▒██░    ▒▓▓▄ ▄██▒▒██   ██░▒██    ▒██ ▒▓█  ▄    $(RED)░$(BLACK) ▓██▓ $(RED)░$(WHITE) ▒██   ██░   ░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░
    ░░██▒██▓ ░▒████▒░██████▒▒ ▓███▀ ░░ ████▓▒░▒██▒   ░██▒░▒████▒     ▒██▒ $(RED)░$(WHITE) ░ ████▓▒░   ░▓█▒░██▓░▒████▒░██████▒░██████▒
endef
define WELCOME_TO_HELL3
    ░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ░  ░░░ ▒░ ░     ▒ ░░   ░ ▒░▒░▒░     ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░
      ▒ ░ ░   ░ ░  ░░ ░ ▒  ░  ░  ▒     ░ ▒ ▒░ ░  ░      ░ ░ ░  ░       ░      ░ ▒ ▒░     ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░
      $(RED)░   ░     ░     ░ ░   ░        ░ ░ ░ ▒  ░      ░      ░        ░      ░ ░ ░ ▒      ░  ░░ ░   ░     ░ ░     ░ ░
       ░       ░  ░    ░  ░░ ░          ░ ░         ░      ░  ░                ░ ░      ░  ░  ░   ░  ░    ░  ░    ░  ░
                            ░$(END)
endef
export WELCOME_TO_HELL1
export WELCOME_TO_HELL2
export WELCOME_TO_HELL3
#################################

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	echo "⏳  $(BLUE)Starting to create Executables$(END)  ⏳"
	$(MAKE) -C $(MINILIB) 2> logs
#	./loading_screen.sh
	echo "✅  $(GREEN)MinilibX Correctly Compiled$(END)  ✅"
	$(MAKE) -C $(LIBFT) ext
	echo "✅  $(GREEN)Libft Correctly Compiled$(END)  ✅"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a -L $(MINILIB) $(FRAMEWORK) -o $(NAME)
	echo "🎊  $(GREEN)Cub3d project correctly compiled$(END)  🎊"
	clear
	echo "$(BLACK)$$WELCOME_TO_HELL1$(END)"
	echo "$(BLACK)$$WELCOME_TO_HELL2$(END)"
	echo "$(RR)$$WELCOME_TO_HELL3$(END)"
	echo "Compilation flags were: $(CFLAGS)"
	$(RM) logs

.c.o: $(FILES) $(INCLUDE)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	echo "🔥  $(RED)Starting to purge objects$(END)  🔥"
	$(MAKE) -C $(MINILIB) clean
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)
	echo "✅  $(GREEN)Objects correctly purged$(END)  ✅"

fclean: clean
	echo "🔥  $(RED)Starting to purge executable$(END)  🔥"
	$(RM) $(NAME)
	$(RM) $(MINILIB)libmlx.a
	$(RM) $(LIBFT)libft.a
	echo "✅  $(GREEN)Executable correctly purged$(END)  ✅"

re: clean all

.PHONY: all re clean fclean
