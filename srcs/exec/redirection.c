/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/07 14:27:54 by marine           ###   ########.fr       */
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
		exit (1);
	}
	arg->fd = open(arg->command[0], O_RDONLY);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		//printf("Fin redirection infile\n");
		exit (1);
	}
	dup2(arg->fd, STDIN_FILENO);
	//printf("Fin redirection infile\n");
	// checker erreur
}

void	redirect_outfile(t_parse *arg)
{
	//printf("Début redirection outfile\n");
	arg->fd = open(arg->command[0], O_WRONLY | O_CREAT | O_TRUNC);
	if (arg->fd == -1)
	{
		printf("Permission denied: %s\n", arg->command[0]);
		//printf("Fin redirection outfile avec erreur grrr\n");
		exit (1); // demander à adam 
	}
	dup2(arg->fd, STDOUT_FILENO);
	// checker erreur
	//printf("Fin redirection outfile\n");
}
