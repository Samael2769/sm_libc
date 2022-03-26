/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** read_from_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *stream = NULL;
    struct stat st;

    if (fd < 0)
        return NULL;
    if (stat(filepath, &st) < 0)
        return NULL;
    stream = malloc(sizeof(char) * (st.st_size + 1));
    if (!stream)
        return NULL;
    if (read(fd, stream, st.st_size) < 0)
        return NULL;
    stream[st.st_size] = '\0';
    close(fd);
    return stream;
}