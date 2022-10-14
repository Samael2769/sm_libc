/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 11:37:52
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 14:36:38
 * @ Description:
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/wait.h>
#include "sm_list.h"
#include <stdbool.h>
#include <signal.h>
#include <sys/uio.h>

#define MAX_CLIENT 30
#define NAME "SM_server"


typedef struct client_s {
    int socket;
    char *buffer;
    int valread;
} client_t;

typedef struct server_s {
    int port;
    int socket;
    fd_set readfds;
    struct sockaddr_in address;
    socklen_t address_len;
    sm_list_t *clients;
    int max_clients;
    int nb_clients;
    int talk_sock;
    char * name;
}server_t;

int server_handler(int port);


//DATA TRANFERT
int receive_msg(int socket, char **buffer);
int send_msg(int socket, char *buffer);

#endif /* !SERVER_H_ */
