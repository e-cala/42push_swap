NAME	=	push_swap
SRC		=	input_check.c main.c push.c utils.c\
			radix.c reverse_rotate.c rotate.c sort.c \
			sort_utils.c stack_functions.c swap.c \
			stack_utils.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
CHECKER	= ./push_swap $(ARG) | ./checker_Mac $(ARG)
#.SILENT:


COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#1. tendria que incluir el .h. Ya que se cambia algo de alli se compila todo de nuevo. Inculir antes de $(OBJ)=> -I push_swap.h
#2. Algunos ficheros son dependientes de otros ya que se cambia una funcion, se modifica la de otras
#3. No es una libreria, por lo tanto el $(NAME) tiene que ser como mi main. ranlib y todo eso sobra aqui


tests:				test1 test2 test3 test4 test5 test100 test500

test1:				$(NAME)
					$(eval ARG = $(shell jot -r 1 -1000 1000))
					@echo "$(COLOUR_BLUE)[1]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l`

test2:				$(NAME)
					$(eval ARG = $(shell jot -r 2 -1000 1000))
					@echo "$(COLOUR_BLUE)[2]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l`

test3:				$(NAME)
					$(eval ARG = $(shell jot -r 3 -1000 1000))
					@echo "$(COLOUR_BLUE)[3]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l`

test4:				$(NAME)
					$(eval ARG = $(shell jot -r 4 -1000 1000))
					@echo "$(COLOUR_BLUE)[4]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l`

test5:				$(NAME)
					$(eval ARG = $(shell jot -r 5 -1000 1000))
					@echo "$(COLOUR_BLUE)[5]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` 


test100:			$(NAME)
					$(eval ARG = $(shell jot -r 100 -1000000 1000000))
					@echo "$(COLOUR_BLUE)[100]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` 

test500:			$(NAME)
					$(eval ARG = $(shell jot -r 500 -1000000 1000000))
					@echo "$(COLOUR_BLUE)[500]$(COLOUR_END) `$(CHECKER)` \t Instructions: " `./push_swap $(ARG) | wc -l` 
.PHONY: clean fclean re all main test1 test2 test3 tests
