# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsausage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 14:23:51 by bsausage          #+#    #+#              #
#    Updated: 2019/12/25 14:23:53 by bsausage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
NAME_VS = visualizer

CC = gcc 
FLAGS = -Wextra -Wall -Werror -g
#LIBRARIES = -lm -lft -L$(LIBFT_DIRECTORY)
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS_DIRECTORY) -I$(MINILIBX_HEADERS)
#-I$(MINILIBX_HEADERS)
#-Wall -Werror -Wextra
# LIBFT

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/
#LIBFT_HEADERS_LIST = libft.h get_next_line.h
LIBFT_HEADERS_DIRECTORY = $(LIBFT_DIRECTORY)includes/

# MINILIBX

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

# PUSH_SWAP

HEADERS_LIST = ft_push_swap.h viz.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))


SOURCES_DIRECTORY = sources/
SOURCES_LIST = free_functions.c list_functions.c operations.c \
check_functions.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

####

#PS_SOURCES_DIRECTORY = sources/
CH_SOURCES_LIST = checker.c 
CH_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(CH_SOURCES_LIST))

CH_OBJECTS_LIST = $(patsubst %.c, %.o, $(CH_SOURCES_LIST))
CH_OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(CH_OBJECTS_LIST))


# VIZUALIZER

#VS_SOURCES_DIRECTORY = sources/
VS_SOURCES_LIST = viz.c init.c drawing.c rgb.c
VS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(VS_SOURCES_LIST))

VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
VS_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(VS_OBJECTS_LIST))


PS_SOURCES_LIST = push_swap.c count_num_oper.c choose_b.c sorting.c sort_short.c
PS_SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(PS_SOURCES_LIST))

PS_OBJECTS_LIST = $(patsubst %.c, %.o, $(PS_SOURCES_LIST))
PS_OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(PS_OBJECTS_LIST))


# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME_CH) $(NAME_PS) #$(NAME_VS)

$(NAME_CH): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS) $(CH_OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(CH_OBJECTS) -o $(NAME_CH)
	@echo "\n$(NAME_CH): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_CH): $(GREEN)$(NAME_CH) was created$(RESET)"

#$(NAME_VS): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS) $(VS_OBJECTS)
#	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(VS_OBJECTS) -o $(NAME_VS)
#	@echo "\n$(NAME_VS): $(GREEN)object files were created$(RESET)"
#	@echo "$(NAME_VS): $(GREEN)$(NAME_VS) was created$(RESET)"

$(NAME_PS): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS) $(PS_OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(PS_OBJECTS) -o $(NAME_PS)
	@echo "\n$(NAME_PS): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_CH): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME_CH): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
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
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(NAME_CH): $(RED)$(NAME_CH) was deleted$(RESET)"
	@rm -f $(NAME_VS)
	@echo "$(NAME_VS): $(RED)$(NAME_VS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
