/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/07/10 00:29:35 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse_del_one(t_parse *node)
{
	if (node->type == infile || node->type == outfile)
		close (node->fd);
	free (node);
}

void	ft_free_2d_array(char **two_di_array)
{
	int	i;

	i = 0;
	while (two_di_array[i])
	{
		ft_bzero(two_di_array[i], ft_strlen(two_di_array[i]));
		free(two_di_array[i]);
		i++;
	}
	free (two_di_array);
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
	if (data->path != NULL)
		ft_free_2d_array(data->path);
}
