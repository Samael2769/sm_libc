/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 15:06:26
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 17:40:34
 * @ Description:
 */

#include "client.h"

int main(int ac, char **av)
{
    int port = atoi(av[2]);
    int type = atoi(av[3]);
    (void)ac;

    if (client_handler(av[1], port, type) != 0)
        return 84;
    return 0;
}