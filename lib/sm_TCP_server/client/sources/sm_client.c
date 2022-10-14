/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 11:44:58
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 15:38:54
 * @ Description:
 */

#include "client.h"

static client_t client_init(char *ip, int port, int type)
{
    client_t client = {
        .type = type,
        .ip = ip,
        .port = port
    };

    if ((client.socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit(84);
    client.address = (struct sockaddr_in){
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = inet_addr(ip)
    };
    client.address_len = sizeof(client.address);
    if (connect(client.socket, (struct sockaddr *)&client.address, client.address_len) < 0)
        exit(84);
    client.server_buffer = malloc(sizeof(char) * 1024);
    client.server_valread = 0;
    client.client_buffer = malloc(sizeof(char) * 1024);
    client.client_valread = 0;
    return client;
}

static int read_user(client_t *client)
{
    if (FD_ISSET(STDIN_FILENO, &client->readfds)) {
        client->client_valread = receive_msg(STDIN_FILENO, &client->client_buffer);
        switch (client->client_valread) {
            case -1:
                return -1;
            default:
                if (send_msg(client->socket, client->client_buffer) == -1)
                    return -1;
                break;
        }
        memset(client->client_buffer, 0, 1024);
    }
    return 0;
}

static int read_server(client_t *client)
{
    if (FD_ISSET(client->socket, &client->readfds)) {
        if ((client->server_valread = receive_msg(client->socket, &client->server_buffer)) < 0)
            return -1;
        fprintf(stderr, "Server: %s", client->server_buffer);
        memset(client->server_buffer, 0, 1024);
    }
    return 0;
}

static int client_run(client_t *client)
{
    int activity = 0;

    while (1) {
        FD_ZERO(&client->readfds);
        FD_SET(STDIN_FILENO, &client->readfds);
        FD_SET(client->socket, &client->readfds);
        if ((activity = select(client->socket + 1, &client->readfds, NULL, NULL, NULL)) < 0)
            return -1;
        if (read_server(client) == -1)
            return -1;
        if (client->type == 0)
            if (read_user(client) == -1)
                return -1;
    }
    return 0;
}

int client_handler(char *ip, int port, int type)
{
    client_t client = client_init(ip, port, type);
    fprintf(stderr, "client connected\n");
    if (client_run(&client) != 0)
        return -1;
    close(client.socket);
    return 0;
}