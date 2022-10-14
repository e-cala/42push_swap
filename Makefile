# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 12:15:58 by ecabanas          #+#    #+#              #
#    Updated: 2022/10/02 12:16:02 by ecabanas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC_PATH	=	src/
SRC		=	input_check.c main.c push.c utils.c\
			radix.c reverse_rotate.c rotate.c sort.c \
			sort_utils.c stack_functions.c swap.c \
			stack_utils.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ		= 	$(SRCS:.c=.o)
DEPS	=	$(addsuffix .d, $(basename $(SRCS)))

HEADER	=	includes/push_swap.h
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror -MMD
RM		= 	rm -f
CHECKER	= 	./push_swap $(ARG) | ./checker/checker_linux $(ARG)

##Revisar esta variable de entorno y ver como funciona
SHELL	=	/bin/sh

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#######################################################################################################################################
all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(CFLAGS) -I $(HEADER) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#######################################################################################################################################
tests:				test0 test1 test2 test3 test4 test5 test100 test500
#make ARG="1 3 4 2" custom
custom:				$(NAME)
					$(eval ARG = $())
					@echo "$(COLOUR_BLUE)[custom]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
					@ ./push_swap $(ARG)

test0:				$(NAME)
					$(eval ARG = $($(SHELL) jot -r 0 -1000 1000))
					@echo "$(COLOUR_BLUE)[0]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test1:				$(NAME)
					$(eval ARG = $(shell jot -r 1 -1000 1000))
					@echo "$(COLOUR_BLUE)[1]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test2:				$(NAME)
					$(eval ARG = $(shell jot -r 2 -1000 1000))
					@echo "$(COLOUR_BLUE)[2]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test3:				$(NAME)
					$(eval ARG = $(shell jot -r 3 -1000 1000))
					@echo "$(COLOUR_BLUE)[3]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test4:				$(NAME)
#					$(eval ARG = $(shell jot -r 4 -1000 1000))
					@echo "$(COLOUR_BLUE)[4]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test5:				$(NAME)
					$(eval ARG = $(shell jot -r 5 -1000 1000))
					@echo "$(COLOUR_BLUE)[5]$(COLOUR_END)   `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` " \t $(ARG)"
#					@ ./push_swap $(ARG)

test100:			$(NAME)
					$(eval ARG = $(shell jot -r 100 -1000000 1000000))
					@echo "$(COLOUR_BLUE)[100]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` 
#					@ ./push_swap $(ARG)

test500:			$(NAME)
					$(eval ARG = $(shell jot -r 500 -1000000 1000000))
					@echo "$(COLOUR_BLUE)[500]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` 
#					@ ./push_swap $(ARG)

.PHONY: all clean fclean re tests test1 test2 test3 test4 test5 test100 test500
