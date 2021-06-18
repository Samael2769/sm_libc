##
## EPITECH PROJECT, 2021
## $(MAKE)file_105torus
## File description:
## ..
##

DIR	=	sources/

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS	=	-I./includes

SRC_FILES	=	sm_printf.c\
				flags/flag_char.c\
				flags/flag_int.c\
				flags/flag_base.c\
				pre_flags/preflag_hash.c\

SRC_MAIN	=	main.c\

MAIN	=	$(addprefix $(DIR), $(SRC_MAIN))

SRC	=	$(addprefix $(DIR), $(SRC_FILES))

MAIN_OBJ	=	$(MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)


LDFLAGS	= -L.

LDLIBS		=	-lsm_libc

CC	=	gcc

AR	=	ar


NAME	=	sm_printf

LIB_NAME	=	libsm_printf.a

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
		$(AR) rc $(LIB_NAME) $(OBJ)

binary: $(OBJ) $(MAIN_OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
		$(RM) -f $(NAME) $(LIB_NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re