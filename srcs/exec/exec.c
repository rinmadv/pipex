/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/07 11:29:06 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_child(t_data *data, t_parse *arg)
{
	if (data->first_arg->type == infile)
	{
		redirect_infile(data->first_arg);
		data->first_arg = data->first_arg->next;
	}
	else if (data->first_arg->type == command
		&& data->first_arg->next->type == outfile)
		redirect_outfile(data->first_arg->next);
	if (!check_cmd(data, arg))
		exit (126); // demander pk 126
	//execve; // à faire
	// besoin d'exit ?
	return (0); // à changer
}

int	execute_parent(t_data *data, t_parse *arg, int *pipe_fd)
{
	if (arg->first_cmd == true)
	{
		*pipe_fd = dup(data->fd[0]);
		close (data->fd[0]);
		close (data->fd[1]);
		if (*pipe_fd == -1)
			return (-1);
	}
	else if (arg->last_cmd == true)
	{
		close (*pipe_fd);
		close (data->fd[0]);
		close (data->fd[1]);
	}
	else
	{
		close (*pipe_fd);
		*pipe_fd = dup(data->fd[0]);
		close (data->fd[0]);
		close (data->fd[1]);
		if (*pipe_fd == -1)
			return (-1);
	}
	return (0);
}

int	exec(t_data *data)
{
	t_parse	*temp;
	int		pid;
	int		pipe_fd;

	temp = data->first_arg; // besoin ou pas
	while (data->first_arg != NULL && data->first_arg->type != outfile)
	{
		if (pipe(data->fd) < 0)
			return (-1);
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
			execute_child(data, data->first_arg);
		else
			execute_parent(data, data->first_arg, &pipe_fd);
		data->first_arg = data->first_arg->next;
	}
	while (wait(NULL) != -1)
	data->first_arg = temp; // besoin ou pas
	// j'exit ou ?
	return (0);
}
