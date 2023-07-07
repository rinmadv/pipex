/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/07 14:27:27 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_child(t_data *data, t_parse *arg)
{
	//printf("Execution enfant %s\n", arg->command[0]);
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
	execve(arg->path, arg->command, data->path);
	//printf("Fin processus enfant %s\n", arg->command[0]);
	return (0); // à changer
}

int	execute_parent(t_data *data, t_parse *arg, int *pipe_fd)
{
	//printf("Execution parent %s\n", arg->command[0]);
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
	//printf("Fin processus parent %s\n", data->first_arg->command[0]);
	return (0);
}

int	exec(t_data *data)
{
	int		pid;
	int		pipe_fd;

	while (data->first_arg != NULL && data->first_arg->type != outfile)
	{
		if (pipe(data->fd) < 0)
			return (-1);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
			execute_child(data, data->first_arg);
		else
			execute_parent(data, data->first_arg, &pipe_fd);
		data->first_arg = data->first_arg->next;
	}
	while (wait(NULL) != -1)
	exit (0);
	return (0);
}
