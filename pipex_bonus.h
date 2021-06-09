#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

int		ft_fork_pipes (int n, char **av, char **env);
void	ft_execute_cmd (char *cmd, char **env);
char	**get_env_path(char **envp);

#endif // PIPEX_BONUS_H
