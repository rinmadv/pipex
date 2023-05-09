/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/05/09 12:55:48 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse_del_one(t_parse *node)
{
	if (node->type == infile || node->type == outfile)
		close (node->fd);
	free (node);
}

void	ft_free_2d_array(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		ft_bzero(path[i], ft_strlen(path[i]));
		free(path[i]);
		i++;
	}
	free (path);
}

void	ft_parse_clear(t_parse **node)
{
	t_parse	*p;

	if (node)
	{
		p = *node;
		while (*node)
		{
			p = (*node)->next;
			ft_free_2d_array((*node)->command);
			free (*node);
			*node = p;
		}
	}
}

void	ft_data_clear(t_data *data)
{
	ft_parse_clear(&data->first_arg);
	ft_free_2d_array(data->path);
}
