/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:52:10 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 22:03:40 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc(char *delimiter)
{
	char	*result;
	int		fd;

	fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//printf("%i\n", fd);
	if (fd < 0)
		return (-1);
	write(1, "heredoc>", 9);
	result = ft_get_next_line(0);
	while (result)
	{
		if ((ft_strlen(result) == (ft_strlen(delimiter) + 1))
			&& ft_strncmp(delimiter, result, (ft_strlen(delimiter))) == 0)
			break ;
		write(fd, result, ft_strlen(result));
		free(result);
		write(1, "heredoc>", 9);
		result = ft_get_next_line(0);
	}
	free(result);
	close(fd);
	return (0);
}
