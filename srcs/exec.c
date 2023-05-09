/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/09 15:47:43 by madavid          ###   ########.fr       */
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

int	exec(t_data *data)
{
	t_data	*temp;

	temp = data;
	if (check_infile(data->first_arg) == -1)
		data->first_arg = data->first_arg->next->next;
	while (data->first_arg->next)
		data->first_arg = data->first_arg->next;
	printf("outfile : %s\n", data->first_arg->command[0]);
	check_outfile(data->first_arg);
	// checker leaks
	// voir ce que je dois faire ...
	data = temp;
	return (0);
}