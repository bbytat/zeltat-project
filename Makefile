# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 04:09:30 by vahemere          #+#    #+#              #
#    Updated: 2022/10/25 01:02:28 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zeltat
OBJS_DIR = objs
SRCS_DIR = $(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir))
SRCS =  main.c init.c game.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))
DEPS = $(OBJS:%.o=%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#fonts color
BLACK =      \033[30m
RED =        \033[31m
YELLOW =     \033[33m
GREEN =      \033[32m
BLUE =       \033[34m
PURPLE =     \033[35m
WHITE =      \033[7m
END =        \033[0m

all: $(NAME)

$(NAME) :  header $(OBJS) progress
	@$(CC) $(CFLAGS) $(OBJS) -lSDL2 -lSDL2_image -o  $(NAME)
	@echo "$(PURPLE) {EXECUTABLE CREATED SUCCESSFULL}$(END)"

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -MMD -o $@ -c $<
	
clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

header : 
	@clear
	@echo "$(RED) ________  _______   ___   _________  ________  _________   $(END)"    
	@echo "$(YELLOW)|\_____  \|\  ___ \ |\  \ |\___   ___\\   __  \|\___   ___\ $(END)"    
	@echo "$(GREEN) \|___/  /\ \   __/|\ \  \\|___ \  \_\ \  \|\  \|___ \  \_| $(END)"    
	@echo "$(BLUE)     /  / /\ \  \_|/_\ \  \    \ \  \ \ \   __  \   \ \  \  $(END)"    
	@echo "$(BLUE)    /  /_/__\ \  \_|\ \ \  \____\ \  \ \ \  \ \  \   \ \  \ $(END)"    
	@echo "$(PURPLE)   |\________\ \_______\ \_______\ \__\ \ \__\ \__\   \ \__\ $(END)"    
	@echo "$(PURPLE)    \|_______|\|_______|\|_______|\|__|  \|__|\|__|    \|__|$(END)\n"

progress :
	@echo "$(RED){COMPILING..}$(END)"
	@echo "[$(GREEN)██$(END)▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)████$(END)▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)█████$(END)▒▒▒▒▒▒▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)███████$(END)▒▒▒▒▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)█████████$(END)▒▒▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)███████████$(END)▒▒▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)█████████████$(END)▒▒▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)███████████████$(END)▒▒▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)█████████████████$(END)▒▒]"
	@sleep 0.2
	@echo "[$(GREEN)███████████████████$(END)]"
	@sleep 0.2
	@echo "$(GREEN)SUCCESSFULL$(END)\n"
	
.PHONY: all clean fclean re header progress

-include $(DEPS)