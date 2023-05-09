/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/09 14:58:32 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	check_infile(t_parse *argument)
{
	int	fd;
	fd = access(argument->command[0], F_OK);
	if (fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", argument->command[0]);
		return (-1);
	}
	fd = open(argument->command[0], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("zsh: permission denied: %s\n", argument->command[0]);
		return (-1);
	}
	return (0);
}

// check outfile
// 	fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC);
// 	if (fd == -1)
// 		return (write(2, "Permission denied\n", 18), -1);

// 	argument->fd = fd;

// int	check_outfile(char *argv, t_parse *argument)
// {
// 	int	fd;

// 	argument = malloc(sizeof(t_parse));
// 	if (argument == NULL)
// 		return (-1);
// 	argument->command = NULL;
// 	argument->type = infile;
// 	argument->path = argv;
// 	ft_node_add_back(argument);
// // 	return (0);
// // }

int	exec(t_data *data)
{
	if (check_infile(data->first_arg) == -1)
		data->first_arg = data->first_arg->next->next;
	return (0);
}