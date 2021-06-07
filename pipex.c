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

t_data *get_last_node(t_data *tmp)
{
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
t_data *get_cmd(char *av)
{
    t_data *cmds;

    cmds = (t_data*) malloc(sizeof(t_data));
    cmds->next = NULL;
    cmds->cmd = ft_split(av, ' ');
    return cmds;
}

t_data *ge_data(int ac , char **av)
{
    int i = 2;
    t_data *data;
    t_data *tmp;
    while (i < (ac - 2))
    {
        if (i == 2)
            data = get_cmd(av[i]);
        else
            tmp = get_last_node(data);
        tmp->next = get_cmd(av[i]);
        i++;
    }
    tmp->next = NULL;
    return data;
}
n 

int main(int ac, char **av, char **env)
{
    puts(av[1]);
    get_data(ac, av);
    puts(av[ac - 1]);

}