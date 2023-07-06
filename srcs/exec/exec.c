/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/06 16:09:20 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_child(t_data *data, t_parse *arg)
{
	if (!check_cmd(data, arg))
		exit (126);
	execve
}

int	exec(t_data *data)
{
	t_parse	*temp;
	int		id;

	temp = data->first_arg;
	while (data->first_arg != NULL && data->first_arg->type != outfile)
	{
		if (pipe(data->fd) < 0)
			return (-1);
		id = fork();
		if (id == -1)
			return (-1);
		else if (id == 0) // is child
		{
			if (data->first_arg->type == infile)
			{
				redirect_infile(data, data->first_arg);
				data->first_arg = data->first_arg->next;
			}
			else if (data->first_arg->type == command
						&& data->first_arg->next->type == outfile)
				redirect_outfile(data, data->first_arg->next);
			execute_child(data, data->first_arg);
		}
		else
			wait( );
		data->first_arg = data->first_arg->next;
	}
	data->first_arg = temp;
	return (0);
}
