/**
 * @ Author: Samael
 * @ Create Time: 2022-10-14 15:06:26
 * @ Modified by: Samael
 * @ Modified time: 2022-10-14 15:34:47
 * @ Description:
 */

#include "client.h"

int main(void)
{
    if (client_handler("127.0.0.1", 8080, 0) != 0)
        return 84;
    return 0;
}