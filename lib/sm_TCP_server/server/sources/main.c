/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 15:09:09
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 17:39:24
 * @ Description:
 */

#include "server.h"

int main(int ac, char **av)
{
    int port = atoi(av[1]);
    (void)ac;

    if (server_handler(port) != 0)
        return 84;
    return 0;
}