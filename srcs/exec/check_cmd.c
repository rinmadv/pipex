/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:54:45 by marine            #+#    #+#             */
/*   Updated: 2023/07/10 00:39:35 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// faire attention aux -1
int	is_path(char *current_arg)
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

int	find_path(t_data *data, t_parse *current_arg, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (data->path && data->path[i])
	{
		cmd_path = ft_strjoin(data->path[i], cmd);
		if (cmd_path == NULL)
			return (-1);
		if (access(cmd_path, F_OK) == 0)
		{
			current_arg->path = cmd_path;
			return (1);
		}
		i++;
		free(cmd_path);
	}
	return (1);
}

int	check_cmd(t_data *data, t_parse *current_arg)
{
	char	*cmd;
	if (!data->path)
	{
		if (is_path(current_arg->command[0]) == 1)
			current_arg->path = current_arg->command[0];
		else
			return (ft_printf(2, "%s: command not found\n", current_arg->path), -1);
	}
	else
	{
		cmd = ft_strjoin("/", current_arg->command[0]);
		if (cmd == NULL)
			return (-1);
		current_arg->path = current_arg->command[0];
		if (find_path(data, current_arg, cmd) == -1)
			return (free(cmd), -1);
		free(cmd);
	}
	if (access(current_arg->path, F_OK) != 0)
		return (ft_printf(2, "%s: command not found\n", current_arg->path), -1);
	if (access(current_arg->path, X_OK) != 0)
		return (ft_printf(2, "%s: permission denied\n", current_arg->path), -1);
	return (1);
}
