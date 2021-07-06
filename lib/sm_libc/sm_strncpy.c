/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sm_strncpy
*/

char *sm_strncpy(char *dest, char *src, int nb)
{
    for (int i = 0; src[i] || i < nb; ++i)
        dest[i] = src[i];
    return dest;
}