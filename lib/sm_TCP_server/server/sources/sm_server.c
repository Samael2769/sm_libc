/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 11:37:44
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 15:39:26
 * @ Description:
 */

#include "server.h"

static server_t server_create(int port)
{
    server_t server = {.port = port};

    if ((server.socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit(84);
    server.address = (struct sockaddr_in){
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };
    server.address_len = sizeof(server.address);
    if (bind(server.socket, (struct sockaddr *)&server.address, server.address_len) < 0)
        exit(84);
    if (listen(server.socket, 3) < 0)
        exit(84);
    server.clients = NULL;
    server.nb_clients = 0;
    server.max_clients = MAX_CLIENT;
    server.name = NAME;
    return server;
}

static int server_check_talking(server_t *server)
{
    client_t *client = NULL;

    for (sm_list_t *tmp = server->clients; tmp; tmp = tmp->next) {
        client = (client_t *)tmp->data;
        if (client->socket > 0)
            FD_SET(client->socket, &server->readfds);
        if (client->socket > server->talk_sock)
            server->talk_sock = client->socket;
    }
    return 0;
}

static int server_cli_handling(server_t *server)
{
    client_t *client = NULL;

    for (sm_list_t *tmp = server->clients; tmp; tmp = tmp->next) {
        client = (client_t *)tmp->data;
        if (FD_ISSET(client->socket, &server->readfds)) {
            client->valread = receive_msg(client->socket, &client->buffer);
            switch (client->valread) {
                case -1:
                    return -1;
                case 0:
                    close(client->socket);
                    client->socket = -1;
                    break;
                default:
                    printf("Client %d: %s", client->socket, client->buffer);
                    send_msg(client->socket, client->buffer);
                    break;
            }
            free(client->buffer);
            client->buffer = malloc(sizeof(char) * 512);
        }
    }
    return 0;
}

static int server_activity(server_t *server)
{
    int entering_socket = -1;
    client_t *client = NULL;

    if (FD_ISSET(server->socket, &server->readfds)) {
        if ((entering_socket = accept(server->socket, (struct sockaddr *)&server->address, &server->address_len)) < 0)
            return -1;
        client = malloc(sizeof(client_t));
        client->socket = entering_socket;
        client->buffer = malloc(sizeof(512));
        client->valread = 0;
        (server->nb_clients == 0) ? server->clients = create_first_node(client, STRUCT) : push_at_end(server->clients, client, STRUCT);
        server->nb_clients++;
        send_msg(entering_socket, "Welcome to the server\n");
    }
    if (server_cli_handling(server) != 0)
        return -1;
    return 0;
}

static int server_run(server_t *server)
{
    int activity = 0;

    printf("%s Running on port %d\n", server->name, server->port);
    while(1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->socket, &server->readfds);
        server->talk_sock = server->socket;
        if (server_check_talking(server) != 0)
            return -1;
        if ((activity = select(server->talk_sock + 1, &server->readfds, NULL, NULL, NULL)) < 0 && errno != EINTR)
            return -1;
        if (server_activity(server) != 0)
            return -1;
    }
    return 0;
}

int server_handler(int port)
{
    server_t server = server_create(port);
    printf("%s Created\n", server.name);
    if (server_run(&server) != 0)
        return -1;
    return 0;
}