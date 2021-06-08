/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:48:47 by aymaatou          #+#    #+#             */
/*   Updated: 2021/06/07 18:48:50 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0777);
	if (fd == -1 || fd2 == -1)
		printf ("Pipex : %s\n", strerror(errno));
	dup2(fd, 0);
	dup2(fd2, 1);
	ft_fork_pipes(ac - 3, av + 2, env);
	close(fd);
	close(fd2);
	return (0);
}
