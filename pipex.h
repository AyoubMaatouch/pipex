#include "libft/library/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


struct command
{
  const char **argv;
};

typedef struct s_data {
    char **cmd;
    struct s_data *next;

} t_data;

int fork_pipes (int n, struct command *cmd);