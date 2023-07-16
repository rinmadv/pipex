/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 21:47:47 by madavid          ###   ########.fr       */
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
	if (data->here_doc > 0)
		unlink(".here_doc");
	ft_parse_clear(&data->first_arg);
	if (data->path != NULL)
		ft_free_2d_array(data->path);
}
