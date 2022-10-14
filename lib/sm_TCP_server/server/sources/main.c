/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 15:09:09
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 15:34:39
 * @ Description:
 */

#include "server.h"

int main(void)
{
    if (server_handler(8080) != 0)
        return 84;
    return 0;
}