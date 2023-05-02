/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/05/02 17:23:32 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_parse	*ft_node_new(char *argv, t_arg_type type)
{
	t_parse	*new_node;

	new_node = malloc(sizeof(t_parse));
	if (new_node == NULL)
		return (NULL);
	new_node->command = ft_split_space(argv);
	if (new_node->command == NULL)
		return (free (new_node), NULL);
	new_node->type = type;
	new_node->path = NULL;
	new_node->fd = -1;
	new_node->next = NULL;
	return (new_node);
}

t_parse	*ft_node_last(t_parse *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_node_add_back(t_parse **node, t_parse *new)
{
	t_parse	*temp;

	if (*node != NULL)
	{
		temp = ft_node_last(*node);
		temp->next = new;
	}
	else
		*node = new ;
}

void	ft_parse_del_one(t_parse *node)
{
	if (node->type == infile || node->type == outfile)
		close (node->fd);
	free (node);
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
			//free char ** command
			//free path
			free (*node);
			*node = p;
		}
	}
}
