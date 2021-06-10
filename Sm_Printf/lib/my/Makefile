##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

SRC		=	sm_realloc.c\
			sm_find_char.c\
			sm_strlen.c\
			sm_strcat.c\

OBJ		=		$(SRC:c=o)

NAME	=		libmy.a

INCLUDE_NAME	=	my.h

DIR_INCLUDE		=	../../includes

AR	=	ar

RM	=	rm

COPY	=	cp

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) rc $(NAME) $(OBJ)
		$(COPY) $(NAME) ../../
		$(COPY) $(INCLUDE_NAME) $(DIR_INCLUDE)

clean:
		$(RM) -f $(OBJ)

fclean: clean
		$(RM) -f $(NAME)
		$(RM) -f ../../$(NAME)

re: fclean all

.PHONY:	all clean fclean re