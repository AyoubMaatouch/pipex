#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


struct command
{
  const char **argv;
};

int fork_pipes (int n, struct command *cmd);