# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Alkor <Alkor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 14:23:51 by bsausage          #+#    #+#              #
#    Updated: 2020/07/12 13:53:37 by Alkor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
NAME_VS = visualizer

CC = gcc 
FLAGS = -Wextra -Wall -Werror -g
LIBRARIES = -lm -lft -L$(LIBFT_DIRECTORY)
VIS_LIBRARIES = -lmlx -lm -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS_DIRECTORY) -I$(MINILIBX_HEADERS)

#LIBFT
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/
LIBFT_HEADERS_DIRECTORY = $(LIBFT_DIRECTORY)includes/

# MINILIBX
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)


HEADERS_LIST = ft_push_swap.h viz.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = sources/
SOURCES_LIST = free_functions.c list_functions_1.c operations_1.c operations_2.c  \
check_functions.c get_index.c fill_stack.c do_undo_operations.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#CHECKER
CH_SOURCES_LIST = main_checker.c read_from_stdin.c  
CH_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(CH_SOURCES_LIST))

CH_OBJECTS_LIST = $(patsubst %.c, %.o, $(CH_SOURCES_LIST))
CH_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(CH_OBJECTS_LIST))

#VISUALIZER
VS_SOURCES_DIRECTORY = sources/
VS_SOURCES_LIST = main_vizualizer.c init.c drawing.c rgb.c gradient.c help.c \
list_functions_2.c key_press.c
VS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(VS_SOURCES_LIST))

VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
VS_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(VS_OBJECTS_LIST))

#PUSH_SWAP
PS_SOURCES_LIST = main_push_swap.c get_markup_status.c count_num_oper.c choose_b.c sorting.c sort_short.c
PS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(PS_SOURCES_LIST))

PS_OBJECTS_LIST = $(patsubst %.c, %.o, $(PS_SOURCES_LIST))
PS_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(PS_OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME_CH) $(NAME_PS) $(NAME_VS)

$(NAME_CH): $(OBJECTS_DIRECTORY) $(OBJECTS) $(CH_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(CH_OBJECTS) $(LIBRARIES) -o $(NAME_CH)
	@echo "$(NAME_CH): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_CH): $(GREEN)$(NAME_CH) was created$(RESET)"

$(NAME_VS): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS) $(VS_OBJECTS)
	@$(CC) $(FLAGS) $(VIS_LIBRARIES) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(VS_OBJECTS) -o $(NAME_VS)
	@echo "$(NAME_VS): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_VS): $(GREEN)$(NAME_VS) was created$(RESET)"

$(NAME_PS): $(OBJECTS_DIRECTORY) $(OBJECTS) $(PS_OBJECTS) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(PS_OBJECTS) $(LIBRARIES) -o $(NAME_PS)
	@echo "$(NAME_PS): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(GREEN)Creating $(LIBFT)$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "MINILIBX: $(GREEN)Creating $(MINILIBX)$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_CH): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME_CH): $(RED)object files were deleted$(RESET)"
	@echo "$(NAME_VS): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME_CH): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(MINILIBX)
	@echo "MINILIBX: $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(NAME_CH): $(RED)$(NAME_CH) was deleted$(RESET)"
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS): $(RED)$(NAME_PS) was deleted$(RESET)"
	@rm -f $(NAME_VS)
	@echo "$(NAME_VS): $(RED)$(NAME_VS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
