/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/06/24 20:07:57 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(t_parse *argument)
{
	argument->fd = access(argument->command[0], F_OK);
	if (argument->fd == -1)
	{
		ft_printf(2, "No such file or directory: %s\n", argument->command[0]);
		return (-1);
	}
	argument->fd = open(argument->command[0], O_RDONLY);
	if (argument->fd == -1)
	{
		ft_printf(2, "Permission denied: %s\n", argument->command[0]);
		return (-1);
	}
	return (0);
}

int	check_outfile(t_parse *argument)
{
	argument->fd = open(argument->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (argument->fd == -1)
	{
		ft_printf(2, "Permission denied: %s\n", argument->command[0]);
		return (-1);
	}
	// close(fd);
	return (0);
}