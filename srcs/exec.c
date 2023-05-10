/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/10 23:42:04 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	check_infile(t_parse *argument)
{
	argument->fd = access(argument->command[0], F_OK);
	if (argument->fd == -1)
	{
		ft_printf(2, "no such file or directory: %s\n", argument->command[0]);
		return (-1);
	}
	argument->fd = open(argument->command[0], O_RDONLY);
	if (argument->fd == -1)
	{
		ft_printf(2, "permission denied: %s\n", argument->command[0]);
		return (-1);
	}
	return (0);
}

int	check_outfile(t_parse *argument)
{
	int	fd;

	fd = open(argument->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		ft_printf(2, "zsh: permission denied: %s\n", argument->command[0]);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

// checker si /

int is_path(t_parse *current_arg)
{
	
}


int	execute(t_data *data, t_parse *current_arg)
{
	int		i;
	char	*command;
	char	*command_path;

	i = 0;
	command = ft_strjoin("/", current_arg->command[0]);
	if (command == NULL)
		return (-1);
	command_path = NULL;
	while(data->path[i])
	{
		command_path = ft_strjoin(data->path[i], command);
		if (command_path == NULL)
		{
			free (command);	
			return (-1);
		}
		if (access(command_path, F_OK) == 0)
		{
			current_arg->path = command_path;
			free(command_path);
			free(command);
			return;
		}
		i++;
		free(command_path);
	}
	current_arg->path = NULL;
	free(command);
}

int	exec(t_data *data)
{
	t_parse	*temp;

	temp = data->first_arg;
	if (check_infile(data->first_arg) == -1)
		data->first_arg = data->first_arg->next->next;
	else
	{	
		// executer la commande
		data->first_arg = data->first_arg->next;
	}
	// while (data->first_arg->next->type != outfile)
	if (data->first_arg->path != NULL)
		execute(data, data->first_arg);
	if (data->first_arg->path != NULL)
	{
		data->first_arg = data->first_arg;
		ft_printf(2, )
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

