/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/09 19:24:30 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(t_data *data, t_parse *arg)
{
	close(data->fd[0]);
	arg->fd = access(arg->command[0], F_OK);
	if (arg->fd == -1)
	{
		printf("No such file or directory: %s\n", arg->command[0]);
		ft_data_clear(data);
		exit (1);
	}
	arg->fd = open(arg->command[0], O_RDONLY);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		ft_data_clear(data);
		exit (1);
	}
	if (dup2(arg->fd, STDIN_FILENO) == -1)
	{
		close(arg->fd);
		ft_data_clear(data);
		exit (1);
	}
}

void	redirect_outfile(t_data *data, t_parse *arg, int pipe_fd)
{
	close(data->fd[0]);
	close(data->fd[1]);
	if (dup2(pipe_fd, STDIN_FILENO) == -1)
			exit (1);
	arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		exit (1);
	}
	if (dup2(arg->fd, STDOUT_FILENO) == -1)
	{
		close(arg->fd);
		ft_data_clear(data);
		exit (1);
	}
}
