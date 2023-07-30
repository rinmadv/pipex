/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:03:25 by madavid           #+#    #+#             */
/*   Updated: 2023/07/30 16:27:43 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	print_err(int type, char *cmd)
{
	char	*str_error;
	char	*begining;

	str_error = NULL;
	begining = ft_strjoin("pipex: ", cmd);
	if (begining == NULL)
		return (-1);
	if (type == CMD)
		str_error = ft_strjoin(begining, " : command not found\n");
	else if (type == PERM)
		str_error = ft_strjoin(begining, " : permission denied\n");
	else
		str_error = ft_strjoin(begining, " : no such file or directory\n");
	if (str_error == NULL)
		return (free (begining), -1);
	ft_printf_fd(2, "%s", str_error);
	free(begining);
	free(str_error);
	return (0);
}

void	redirection_error(int err, char *cmd, t_data *data)
{
	print_err(err, cmd);
	ft_data_clear(data);
	exit (1);
}
