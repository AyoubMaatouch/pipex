/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:48:47 by aymaatou          #+#    #+#             */
/*   Updated: 2021/06/07 18:48:50 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *file)
{
	write(2, "Pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
}

char	**get_env_path(char **envp)
{
	int		i;
	char	*s;
	char	**paths;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0 && envp[i][4] == '=')
		{
			s = ft_strchr(envp[i], '=') + 1;
			paths = ft_split_path(s, ':');
			return (paths);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd;
	int	fd2;
	int	err;

	err = 0;
	if (ac < 5)
		return (write(2, "Pipex: Argument Error\n", 22));
	else
	{
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
		if (fd == -1)
		{
			msg_error(av[1]);
			err = 1;
		}
		if (fd2 == -1)
			msg_error(av[ac - 1]);
		dup2(fd, 0);
		dup2(fd2, 1);
		ft_fork_pipes(ac - (3 + err), av + (2 + err), env);
		close(fd);
		close(fd2);
	}
	return (0);
}
