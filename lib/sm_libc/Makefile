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
			sm_strconcat.c\
			sm_calloc.c\
			sm_itoa.c\
			sm_revstr.c\
			sm_convert_base.c\
			sm_strcpy.c\
			sm_strdup.c\
			sm_strcmp.c\
			sm_putstr.c\
			sm_freetab.c\
			sm_atoi.c\
			sm_strstr.c\
			sm_count_char.c\
			sm_pow.c\
			sm_ftoa.c\
			sm_strncpy.c\
			sm_substr.c\
			sm_get_next_line.c\
			sm_data_tranfert.c\

OBJ		=		$(SRC:c=o)

NAME	=		libsm_libc.a

INCLUDE_NAME	=	sm_libc.h

#####################################
TEST_NAME	=	unit_test

DIR_TEST	=	tests/

TEST_ADD	=	tests_

SRC_TEST	=	$(addprefix $(TEST_ADD), $(SRC))

OBJ_TEST	=	$(addprefix $(DIR_TEST), $(SRC_TEST))

LDLIBS	=	--coverage -lcriterion

COVR	=	gcovr
#####################################

AR	=	ar

RM	=	rm

COPY	=	cp

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) rc $(NAME) $(OBJ)

clean:
		$(RM) -f $(OBJ)

fclean: clean
		$(RM) -f $(NAME)
		$(RM) -f *gc*
		$(RM) -f $(TEST_NAME)

unit_test: fclean $(NAME)
	touch $(OBJ_TEST)
	gcc -o $(TEST_NAME) $(SRC) $(OBJ_TEST) $(LDLIBS)

tests_run:	unit_test
	./$(TEST_NAME)
	$(COVR) --exclude $(DIR_TEST)
	$(COVR) --exclude $(DIR_TEST) --branch

re: fclean all

.PHONY:	all clean fclean re