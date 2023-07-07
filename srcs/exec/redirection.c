/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/07 11:26:33 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(t_parse *arg)
{
	arg->fd = access(arg->command[0], F_OK);
	if (arg->fd == -1)
	{
		ft_printf(2, "No such file or directory: %s\n", arg->command[0]);
		exit (1);
	}
	arg->fd = open(arg->command[0], O_RDONLY);
	if (arg->fd == -1)
	{
		ft_printf(2, "Permission denied: %s\n", arg->command[0]);
		exit (1);
	}
	dup2(arg->fd, STDIN_FILENO);
	// checker erreur
}

void	redirect_outfile(t_parse *arg)
{
	arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (arg->fd == -1)
	{
		ft_printf(2, "Permission denied: %s\n", arg->command[0]);
		exit (1); // demander à adam 
	}
	dup2(arg->fd, STDOUT_FILENO);
	// checker erreur
}
