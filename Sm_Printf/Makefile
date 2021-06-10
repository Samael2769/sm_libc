##
## EPITECH PROJECT, 2021
## $(MAKE)file_105torus
## File description:
## ..
##

DIR	=	sources/

DIR_LIB	=	lib/my

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS	=	-I./includes

SRC_FILES	=	sm_printf.c\
				flags/flag_char.c\

SRC_MAIN	=	main.c\

MAIN	=	$(addprefix $(DIR), $(SRC_MAIN))

SRC	=	$(addprefix $(DIR), $(SRC_FILES))

MAIN_OBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)


LDFLAGS	= -L.

LDLIBS		=	-lmy

CC	=	gcc

AR	=	ar


NAME	=	sm_printf

LIB_NAME	=	libmyprintf.a

all: $(LIB_NAME)

$(LIB_NAME): make_lib $(OBJ)
		$(AR) rc $(LIB_NAME) $(OBJ)

binary: make_lib $(OBJ) $(MAIN_OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LDFLAGS) $(LDLIBS)

make_lib:
		$(MAKE) -sC $(DIR_LIB)

clean:
		$(MAKE) -sC $(DIR_LIB) clean
		$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
		$(RM) -f $(NAME) $(LIB_NAME)
		$(MAKE) -sC $(DIR_LIB) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re