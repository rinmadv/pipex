/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/09 18:31:31 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(t_data *data, t_parse *arg)
{
	if (arg->type == infile)
	{
		redirect_infile(arg);
		arg = arg->next;
	}
	else if (arg->type == command && arg->next->type == outfile)
		if (redirect_outfile(arg->next) == -1)
			exit (1);
	if ((arg->type == command && arg->next->type != outfile))
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
			exit (1);
	if (!check_cmd(data, arg))
		exit (1);
	execve(arg->path, arg->command, data->path);
	ft_data_clear(data);
	exit(1);
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
		{
			if (execute_parent(data, data->first_arg, &pipe_fd) == -1)
				return (-1);
		}
		if (data->first_arg->type == infile)
			data->first_arg = data->first_arg->next;
		data->first_arg = data->first_arg->next;
	}
	while ((pid = wait(NULL)) >= 0)
	exit (0);
	return (0);
}
