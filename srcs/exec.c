/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/06/21 23:26:04 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int is_path(char *current_arg)
{
	int	i;

	i = 0;
	while (current_arg[i])
	{
		if (current_arg[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int find_path(t_data *data, t_parse *current_arg,char *cmd,char *cmd_path)
{
	int		i;

	i = 0;
	while(data->path[i])
	{
		cmd_path = ft_strjoin(data->path[i], cmd);
		if (cmd_path == NULL)
		{
			free (cmd);	
			return (-1);
		}
		if (access(cmd_path, F_OK) == 0)
		{
			current_arg->path = cmd_path;
			free(cmd_path);
			free(cmd);
			return (1);
		}
		i++;
		free(cmd_path);
	}
}

/* a checker */
int	check_cmd(t_data *data, t_parse *current_arg)
{
	char	*cmd;
	char	*cmd_path;

	if (is_path(current_arg->command[0]) == 1)
	{
		cmd_path = current_arg->command[0];
		if (access(cmd_path, F_OK) == 0)
		{
			current_arg->path = cmd_path;
			return (free(cmd_path), 1);
		}
		else
			return (free(cmd_path), -1);
	}
	else
	{
		cmd = ft_strjoin("/", current_arg->command[0]);
		if (cmd == NULL)
			return (-1);
		cmd_path = NULL;
		if (find_path(data, current_arg, cmd, cmd_path) == - 1)
			return (-1);
		current_arg->path = NULL;
		free(cmd);
		return (-1);
	}
}

int	exec(t_data *data)
{
	t_parse	*temp;

	temp = data->first_arg;









	
	if (check_infile(data->first_arg) == -1)
		data->first_arg = data->first_arg->next->next;
	else
	{	
		
		//lire le fichier
		// executer la commande
		// execve()
		printf("path to cmd = [%s]\n", )
		printf("")
		printf("")
		printf("")
		data->first_arg = data->first_arg->next;
	}

	/* Plus tard
	// while (data->first_arg->next->type != outfile)
	if (data->first_arg->path != NULL)
		execute(data, data->first_arg);
	if (data->first_arg->path != NULL)
	{
		data->first_arg = data->first_arg;
		ft_printf(2, "Path : %s\n", data->first_arg->path[0]);
	}
	(void) data;
		//executer les autres commandes;
	/* check de la derniere commande
	printf("outfile : %s\n", data->first_arg->command[0]);
	if (check_outfile(data->first_arg) == -1)
		return (-1);
	else
		//executer la derniere commande
	*/
	data->first_arg = temp;
	return (0);
}



while (we have cmds to run)
{
	pid = fork();
	if (pid == 0) si c'est l'enfant
	{
		do exec stuff, l'enfant va faire nos affaires et executer la command
		
	}
	else		si c'est le parent on continue le while
	
}

dup2(infile, STDIN_FILENO);

on a lance tous les enfants 
-> on wait les enfants, le temps qu'ils finissent leur execution




first child > infile

all the childs in the middle 

last child > outfile

le gros probleme ==== PIPES et dans une moindre mesure les dups
