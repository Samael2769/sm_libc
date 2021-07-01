/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sm_pow
*/

int sm_pow(int nb, int power)
{
    int res = 1;

    for (int i = 0; i < power; ++i)
        res *= nb;
    return res;
}