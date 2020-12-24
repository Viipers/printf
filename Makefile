# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 11:00:45 by tsannie           #+#    #+#              #
#    Updated: 2020/12/19 21:41:59 by tsannie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= @gcc
INCLUDES	= -I./includes
LIBFT		= libft

RM			= @rm -rf

SOURCES		= ft_printf.c trim_param.c arg_1.c arg_2.c align.c \
ft_tools_count1.c ft_tools_count2.c point.c star.c

BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
BOLD		:=$(shell tput -Txterm bold)
END			:= $(shell tput -Txterm sgr0)
NAMEC		= ${BLUE}${BOLD}$(NAME)${END}


SRCS 		= $(addprefix src/, $(SOURCES))

OBJ			= $(addprefix src/, $(SOURCES:.c=.o))

all:		$(NAME)

$(NAME): 	$(OBJ)
			@make bonus -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "${GREEN}The $(NAMEC) ${GREEN}has been build !${END}"

test:
			@make all
			@make clean
			$(CC) main.c $(NAME)

clean:
			@make clean -C $(LIBFT)
			$(RM) $(OBJ) $(BONUS_OBJ)
			@echo "${YELLOW}The $(NAMEC) ${YELLOW}has been cleaned up !" \
			 "(with ${BOLD}${WHITE}$@${END}${YELLOW}) !${END}"

fclean:		clean
			@make fclean -C $(LIBFT)
			$(RM) $(NAME)
			@echo "${YELLOW}The $(NAMEC) ${YELLOW}has been cleaned up !" \
			 "(with ${BOLD}${WHITE}$@${END}${YELLOW}) !${END}"

re:			fclean all

.PHONY:		all test clean fclean re
