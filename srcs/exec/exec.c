/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/30 16:54:39 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(t_data *data, t_parse *arg, int pipe_fd)
{
	if (arg->type == infile)
	{
		redirect_infile(data, arg);
		arg = arg->next;
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		{
			ft_data_clear(data);
			exit (1);
		}
	}
	else if (arg->type == command && arg->next->type == outfile)
		redirect_outfile(data, arg->next, pipe_fd);
	else
		redirect_cmd(data, pipe_fd);
	close(data->fd[1]);
	if (check_cmd(data, arg) < 0)
	{
		ft_data_clear(data);
		exit (1);
	}
	execve(arg->path, arg->command, data->path);
	ft_data_clear(data);
	exit (1);
}

int	execute_parent(t_data *data, t_parse *arg, int *pipe_fd)
{
	if (arg->first_cmd == true)
	{
		if (*pipe_fd != -1)
			close(*pipe_fd);
		*pipe_fd = dup(data->fd[0]);
		close (data->fd[0]);
		close (data->fd[1]);
		if (*pipe_fd == -1)
			return (-1);
	}
	else if (arg->last_cmd == true)
		return (close (*pipe_fd), close (data->fd[0]), close (data->fd[1]));
	else
	{
		if (*pipe_fd != -1)
			close(*pipe_fd);
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
	t_parse	*tmp;

	pipe_fd = -1;
	tmp = data->first_arg;
	while (tmp != NULL && tmp->type != outfile)
	{
		if (pipe(data->fd) < 0)
			return (-1);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
			execute_child(data, tmp, pipe_fd);
		else if (execute_parent(data, tmp, &pipe_fd) == -1)
			return (-1);
		if (tmp->type == infile)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	pid = wait(NULL);
	while ((pid) >= 0)
		pid = wait(NULL);
	return (0);
}
