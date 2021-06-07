/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:04:27 by aymaatou          #+#    #+#             */
/*   Updated: 2021/06/07 19:05:38 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int exec_childs (int in,  int *out, struct command *cmd)
{
	pid_t pid;

	if ((pid = fork ()) == 0)
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
		execvp (cmd->argv [0], (char * const *)cmd->argv);
		exit(0);
	}
	return pid;
}

int last_child (int in, int *fd, struct command *cmd, int i, int n)
{
	pid_t x;
	int ret; 

	x = fork();
	if (x == 0)
	{
		dup2 (in, 0);
		close(in);
		close (fd[0]);
		execvp (cmd [i].argv [0], (char * const *)cmd [i].argv);
		exit(0);
	} 
	close (fd[0]);
	waitpid(x,&ret, 0 );
	i = 0;
	while (i < n - 1)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
int fork_pipes (int n, struct command *cmd)
{
	int i;
	pid_t pid;
	int in, fd [2];

	in = 0;
	for (i = 0; i < n - 1; ++i)
	{
		pipe (fd);
		exec_childs (in, fd , cmd + i);
		close (fd [1]); 
		if (i != 0)
			close(in);
		in = fd [0];
		// close(fd[0]);
	}
	return last_child (in, fd, cmd, i, n);
}
