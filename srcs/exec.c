/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/06/24 20:11:12 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int is_path(char *current_arg)
{
	int i;

	i = 0;
	while (current_arg[i])
	{
		if (current_arg[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int find_path(t_data *data, t_parse *current_arg, char *cmd, char *cmd_path)
{
	int i;

	i = 0;
	while (data->path[i])
	{
		cmd_path = ft_strjoin(data->path[i], cmd);
		if (cmd_path == NULL)
		{
			free(cmd);
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
int check_cmd(t_data *data, t_parse *current_arg)
{
	char *cmd;
	char *cmd_path;

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
		if (find_path(data, current_arg, cmd, cmd_path) == -1)
			return (-1);
		current_arg->path = NULL;
		free(cmd);
		return (-1);
	}
}

void redirect(t_data *data, t_parse *arg)
{
	if (arg->type == infile)
	{
		check_infile(arg);
		close(data->fd[1]); //ferme l'entre
		dup2(arg->fd, data->fd[1]);
		close(arg->fd);
	}
	else if (arg->type == outfile)
	{
		/* code */
	}
	else
	{
		check_outfile(arg);
		close(data->fd[0]);
		dup2(arg->fd, data->fd[0]);
		close(arg->fd);
		// je fais quoi si le retour de check outfile est -1 ? je close mais mais output vont ou ??
	}
}

int exec(t_data *data)
{
	t_parse *temp;
	int id;

	temp = data->first_arg;
	while (data->first_arg->type != NULL)
	{
		if (pipe(data->fd) == -1)
			return (-1);
		id = fork();
		if (id != 0)
			wait();
		if (id == 0) // is child
		{

			
		}
		else
			// autre chose
			data->first_arg = data->first_arg->next;
	}
	data->first_arg = temp;
	return (0);
}
