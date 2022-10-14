/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 12:06:17
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 14:52:08
 * @ Description:
 */

#pragma once

    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <signal.h>
    #include <sys/uio.h>

    typedef struct client_s {
        int socket;
        char * ip;
        int port;
        char * server_buffer;
        int server_valread;
        char * client_buffer;
        int client_valread;
        int type;
        struct sockaddr_in address;
        socklen_t address_len;
        fd_set readfds;
    } client_t;

    int client_handler(char *ip, int port, int type);

    //DATA TRANSFERT
    int receive_msg(int socket, char **buffer);
    int send_msg(int socket, char *buffer);

