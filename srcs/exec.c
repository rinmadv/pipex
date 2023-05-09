/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/09 23:55:56 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	check_infile(t_parse *argument)
{
	int	fd;

	fd = access(argument->command[0], F_OK);
	if (fd == -1)
	{
		ft_printf(2, "zsh: no such file or directory: %s\n", argument->command[0]);
		close(fd);
		return (-1);
	}
	fd = open(argument->command[0], O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "zsh: permission denied: %s\n", argument->command[0]);
		close(fd);
		return (-1);
	}
	close(fd);
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


int	do_command(t_data *data, t_parse *current_arg)
{
	int		i;
	char	*command;
	char	*command_path;
	int		return_value;

	i = 0;
	command = ft_strjoin("/", current_arg->command[0]);
	command_path = NULL;
	while(data->path[i])
	{
		command_path = ft_strjoin(data->path[i], command);
		return_value = access(command_path, F_OK);
		if (return_value == 0)
		{
			free(command_path);
			free(command);
			return(1);
		}
		i++;
		free(command_path);
	}
	free(command); // penser a free s ca free
	return (0);
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
		do_command(data, data->first_arg);
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