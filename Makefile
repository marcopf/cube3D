# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marco <marco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 14:12:38 by marco             #+#    #+#              #
#    Updated: 2023/05/06 15:15:47 by marco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube3D

SRC			= main.c

OBJ		= $(SRC:%.c=%.o)

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
MLX		= -L . -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RESET	= \033[0;0m

$(NAME): $(OBJ)
	@make -C mlx
	@cp mlx/libmlx.dylib .
	@$(CC) $(FLAGS) $(OBJ) $(MLX) -o $(NAME)
	@printf "\r\033[KCUBE3D  CREATED  SUCCESSUFULLY\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "  ██████╗██╗   ██╗██████╗ ███████╗██████╗ ██████╗ \n"
	@printf " ██╔════╝██║   ██║██╔══██╗██╔════╝╚════██╗██╔══██╗\n"
	@printf " ██║     ██║   ██║██████╔╝█████╗   █████╔╝██║  ██║\n"
	@printf " ██║     ██║   ██║██╔══██╗██╔══╝   ╚═══██╗██║  ██║\n"
	@printf " ╚██████╗╚██████╔╝██████╔╝███████╗██████╔╝██████╔╝\n"
	@printf "  ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═════╝ ╚═════╝ \n"
	@printf "\n$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "$(YELLOW)Made with love and bestemmie by Afraccal e Mpaterno.\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"

%.o : %.c
	@$(CC) $(FLAG) -Imlx -c $< -o $@

all: $(NAME)

linux: $(OBJ)
	$(CC) -fsanitize=address $(OBJ) $(RDLN_L) -o $(NAME)

clean:
	@make -C mlx clean
	@printf "$(RED)\nRemoving Object files...\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@$(RM) $(OBJ)
	@printf "$(RED)Object files removed\n$(RESET)"
	
fclean: clean
	@rm libmlx.dylib
	@printf "$(RED)\nRemoving program executable...\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@$(RM) $(NAME)
	@printf "$(RED)CUDE3D REMOVED\n$(RESET)"
	
re: fclean all

.PHONY: all clean fclean re test