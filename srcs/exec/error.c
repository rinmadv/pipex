/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:03:25 by madavid           #+#    #+#             */
/*   Updated: 2023/07/16 19:08:08 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_err(int type, char *cmd)
{
	if (type == CMD)
		ft_printf(2, "pipex: %s: command not found\n", cmd);
	else if (type == PERM)
		ft_printf(2, "pipex: %s: permission denied\n", cmd);
	else
		ft_printf(2, "pipex: %s: No such file or directory\n", cmd);
	return (-1);
}

void	redirection_error(int err, char *cmd, t_data *data)
{
	print_err(err, cmd);
	ft_data_clear(data);
	exit (1);
}
