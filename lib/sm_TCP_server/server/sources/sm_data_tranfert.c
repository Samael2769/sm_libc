/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_data_tranfert
*/

#include "unistd.h"
#include "string.h"

int receive_msg(int socket, char **buffer)
{
    int valread = read(socket, *buffer, 1024);
    return valread;
}

int send_msg(int socket, char *buffer)
{
    int valread = 0;
    if ((valread = write(socket, buffer, strlen(buffer)) < 0))
        return -1;
    return valread;
}