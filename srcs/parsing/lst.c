/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:48 by marine            #+#    #+#             */
/*   Updated: 2023/07/07 18:03:27 by marine           ###   ########.fr       */
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
	new_node->first_cmd = false;
	new_node->last_cmd = false;
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

void	print_lst(t_parse *node)
{
	int	i;
	int	j;

	i = 0;
	while (node)
	{
		j = 0;
		while (node->command[j])
		{
			printf("arg [%d][%d] = %s\tpremière cmd ? : %d\tdernière cmd ? : %d, \n", i, j, node->command[j], node->first_cmd, node->last_cmd);
			j++;
		}
		i++;
		node = node->next;
	}
}
