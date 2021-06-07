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



int main(int ac, char **av, char **env)
{
    

  const char *ls[] = { "cat", NULL };
  const char *awk[] = { "ls", NULL };
  const char *sort[] = { "ls", NULL };
  const char *uniq[] = { "ls", NULL };
  struct command cmd [] = { {ls}, {awk},  {sort}, {uniq} };

  return 
  fork_pipes (4, cmd);
}