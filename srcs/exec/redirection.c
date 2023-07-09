/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/09 18:14:23 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(t_parse *arg)
{
	//printf("Début redirection infile\n");
	arg->fd = access(arg->command[0], F_OK);
	if (arg->fd == -1)
	{
		printf("No such file or directory: %s\n", arg->command[0]);
		//printf("Fin redirection infile\n");
		//free
		exit (1);
	}
	arg->fd = open(arg->command[0], O_RDONLY);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		//printf("Fin redirection infile\n");
		// ft_data_clear(data);
		exit (1);
	}
	if (dup2(arg->fd, STDIN_FILENO) == -1)
	{
		close(arg->fd);
		//free
		exit (1);
	}
	//printf("Fin redirection infile\n");
}

int	redirect_outfile(t_parse *arg)
{
	//printf("Début redirection outfile\n");
	arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		//printf("Fin redirection outfile avec erreur grrr\n");
		return (-1); // demander à adam 
	}
	if (dup2(arg->fd, STDOUT_FILENO) == -1)
		return (close(arg->fd), -1);
	return (0);
	//printf("Fin redirection outfile\n");
}
