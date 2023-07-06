/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/06 22:21:43 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_child(t_data *data, t_parse *arg)
{
	//signal
	if (data->first_arg->type == infile)
	{
		redirect_infile(data, data->first_arg);
		data->first_arg = data->first_arg->next;
	}
	else if (data->first_arg->type == command
				&& data->first_arg->next->type == outfile)
		redirect_outfile(data, data->first_arg->next);
	if (!check_cmd(data, arg))
		exit (126);
	execve; // à faire 
	return (0); // à changer
}
int	execute_parent(t_data *data, t_parse *arg)
{
	// signal
			/* 
			si on est dans la première commande (index 0)
				pipe_fd = dup(data->fd[0]);
				close (data->fd[0]);
				close (data->fd[1]);
				check erreur dup
			sinon si on es dans la derniere commande (index n)
				close (pipe_fd);
				close (data->fd[0]);
				close (data->fd[1]);
			sinon (milieu)
				close (pipe_fd);
				pipe_fd = dup(data->fd[0]);
				close (data->fd[0]);
				close (data->fd[1]);
				check erreur dup
			*/
}



int	exec(t_data *data)
{
	t_parse	*temp;
	int		pid;
	int		pipe_fd;

	temp = data->first_arg;
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
			execute_parent(data, data->first_arg);
		data->first_arg = data->first_arg->next;
	}
	wait();
	data->first_arg = temp;
	return (0);
}
