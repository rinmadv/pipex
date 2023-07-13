/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:52:10 by marine            #+#    #+#             */
/*   Updated: 2023/07/13 22:40:47 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc(char *delimiter)
{
	char	*path;
	char	*result;
	int		fd;

	path = ".goinfre/here_doc";
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	write(1, "hererdoc>", 10);
	result = ft_get_next_line(0);
	while (result)
	{
		if ((strlen(result) == (ft_strlen(delimiter) + 1))
			&& ft_strncmp(delimiter, result, (strlen(delimiter))) == 0)
			break ;
		write(fd, result, strlen(result));
		free(result);
		write(1, "hererdoc>", 10);
		result = ft_get_next_line(0);
	}
	free(result);
	close(fd);
	return (0);
}
