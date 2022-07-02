##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

DIR_PRINTF = lib/sm_printf

DIR_LIB	=	lib/sm_libc

DIR_LIST	=	lib/sm_linked

LIB_NAME	=	libsm_libc.a

LIB_PRINTF_NAME	=	libsm_printf.a

LIB_LIST_NAME	=	libsm_list.a

NAME	=	sm_libc

CP	=	cp

all: $(NAME)

$(NAME): make_lib printf

printf: make_lib
	$(MAKE) -sC $(DIR_PRINTF)
	$(CP) $(DIR_PRINTF)/$(LIB_PRINTF_NAME) ./

binary_printf: fclean make_lib
	$(MAKE) -sC $(DIR_PRINTF) binary
	$(CP) $(DIR_PRINTF)/sm_printf ./

make_lib:
	$(MAKE) -sC $(DIR_LIB)
	$(CP) $(DIR_LIB)/$(LIB_NAME) $(DIR_PRINTF)
	$(CP) $(DIR_LIB)/sm_libc.h	$(DIR_PRINTF)/includes

list:
	$(MAKE) -sC $(DIR_LIST)
	$(CP) $(DIR_LIST)/$(LIB_LIST_NAME) ./

binary_list:
	$(MAKE) -sC $(DIR_LIST) binary
	$(CP) $(DIR_LIST)/sm_list ./

clean:
	$(MAKE) -sC $(DIR_PRINTF) clean
	$(MAKE) -sC $(DIR_LIB) clean
	$(MAKE) -sC $(DIR_LIST) clean

fclean:
	$(MAKE) -sC $(DIR_PRINTF) fclean
	$(MAKE) -sC $(DIR_LIB) fclean
	$(RM) $(DIR_PRINTF)/$(LIB_NAME)
	$(RM) ./$(LIB_PRINTF_NAME)
	$(RM) ./sm_printf
	$(MAKE) -sC $(DIR_LIST) fclean
	$(RM) $(LIB_LIST_NAME)
	$(RM) sm_list

tests_run:
	@echo "testing"
	$(MAKE) -sC $(DIR_LIB) tests_run

bash_test: fclean $(NAME)
	./$(DIR_PRINTF)/tests/test_sm_printf.sh