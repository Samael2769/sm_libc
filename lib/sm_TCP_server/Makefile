#/**
# * @ Author: Samael
# * @ Create Time: 2022-10-14 15:04:16
# * @ Modified by: Samael
# * @ Modified time: 2022-10-14 15:46:07
# * @ Description:
# */

SERV = ./server

CLIENT = ./client

SERV_NAME = sm_server

CLIENT_NAME = sm_client

CP = cp

all: server client

server:
	@$(MAKE) -C $(SERV)
	$(CP) $(SERV)/$(SERV_NAME) .

client:
	@$(MAKE) -C $(CLIENT)
	$(CP) $(CLIENT)/$(CLIENT_NAME) .

clean:
	@$(MAKE) -C $(SERV) clean
	@$(MAKE) -C $(CLIENT) clean

fclean:
	@$(MAKE) -C $(SERV) fclean
	@$(MAKE) -C $(CLIENT) fclean
	$(RM) $(SERV_NAME)
	$(RM) $(CLIENT_NAME)

re: fclean all

.PHONY: all server client clean fclean re
