/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 21:24:46 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(t_data *data, t_parse *arg)
{
	close(data->fd[0]);
	if (!arg->command[0])
		redirection_error(NOFILEDIR, "", data);
	if (access(arg->command[0], F_OK) == -1)
	{
		close(data->fd[1]);
		redirection_error(NOFILEDIR, arg->command[0], data);
	}
	arg->fd = open(arg->command[0], O_RDONLY);
	if (arg->fd == -1)
		redirection_error(PERM, arg->command[0], data);
	if (dup2(arg->fd, STDIN_FILENO) == -1)
	{
		close(arg->fd);
		ft_data_clear(data);
		exit (1);
	}
	close(arg->fd);
}

void	redirect_outfile(t_data *data, t_parse *arg, int pipe_fd)
{
	(void)pipe_fd;
	close(data->fd[0]);
	close(data->fd[1]);
	if (dup2(pipe_fd, STDIN_FILENO) == -1)
	{
		ft_data_clear(data);
		exit (1);
	}
	close(pipe_fd);
	if (!arg->command[0])
		redirection_error(NOFILEDIR, "", data);
	if (data->here_doc == -1)
		arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (arg->fd == -1)
		redirection_error(PERM, arg->command[0], data);
	if (dup2(arg->fd, STDOUT_FILENO) == -1)
	{
		close(arg->fd);
		ft_data_clear(data);
		exit (1);
	}
	close(arg->fd);
}

void	redirect_cmd(t_data *data, int pipe_fd)
{
	if (dup2(pipe_fd, STDIN_FILENO) == -1)
	{
		ft_data_clear(data);
		exit (1);
	}
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		ft_data_clear(data);
		exit (1);
	}
	close(pipe_fd);
	close(data->fd[0]);
}
