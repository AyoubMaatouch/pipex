/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_children_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:04:27 by aymaatou          #+#    #+#             */
/*   Updated: 2021/06/07 19:05:38 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_cmd (char *cmd, char **env)
{
	char	**re_env;
	int		i;
	int		res;
	char	*tmp;

	re_env = get_env_path(env);
	i = 0;
	if (cmd[0] == '/')
		res = execve (ft_split(cmd, ' ')[0], ft_split(cmd, ' '), env);
	else
	{
		while (re_env[i])
		{
			tmp = ft_strjoin(re_env[i], cmd);
			res = execve (ft_split(tmp, ' ')[0], ft_split(tmp, ' '), env);
			free(tmp);
			i++;
		}
		if (res == -1)
		{
			write(2, "Pipex: Command Not Found\n", 25);
			exit(1);
		}	
	}
}

int	exec_childs (int in, int *out, char *av, char **env)
{
	int	pid;

	pid = fork ();
	if (pid == 0)
	{
		if (in != 0)
		{
			dup2 (in, 0);
			close (in);
		}
		if (out[1] != 1)
		{
			dup2 (out[1], 1);
			close (out[1]);
			close (out[0]);
		}
		close(out[0]);
		ft_execute_cmd(av, env);
		exit(0);
	}
	return (pid);
}

int	last_child (int in, int *fd, char **env, char *av)
{
	int	x;
	int	ret;

	x = fork();
	if (x == 0)
	{
		dup2 (in, 0);
		close(in);
		close (fd[0]);
		ft_execute_cmd(av, env);
		exit(0);
	}
	close (fd[0]);
	waitpid(x, &ret, 0);
	return (0);
}

int	ft_fork_pipes (int n, char **av, char **env)
{
	int	i;
	int	in;
	int	fd[2];

	in = 0;
	i = 0;
	while (i < n - 1)
	{
		pipe (fd);
		exec_childs(in, fd, av[i], env);
		close (fd[1]);
		if (i != 0)
			close(in);
		in = fd [0];
		i++;
	}
	last_child (in, fd, env, av[i]);
	i = 0;
	while (i < n - 1)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
