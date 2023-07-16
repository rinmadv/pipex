/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parse_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 21:54:37 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_node(t_parse *new_node, t_arg_type type)
{
	new_node->type = type;
	new_node->path = NULL;
	new_node->fd = -1;
	new_node->next = NULL;
	new_node->first_cmd = false;
	new_node->last_cmd = false;
}

t_parse	*ft_node_new(char *argv, t_arg_type type, t_data *data)
{
	t_parse	*new_node;

	new_node = malloc(sizeof(t_parse));
	if (new_node == NULL)
		return (NULL);
	if (type == infile && data->here_doc == 1)
		new_node->command = ft_split_space(".here_doc");
	else
		new_node->command = ft_split_space(argv);
	if (new_node->command == NULL)
		return (free(new_node), NULL);
	init_node(new_node, type);
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
