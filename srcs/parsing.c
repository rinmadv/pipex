/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:57:26 by marine            #+#    #+#             */
/*   Updated: 2023/06/21 23:06:04 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_envp(t_data *data, char **envp)
{
	int		i;

	i = 0;
	if (!envp)
	{
		data->path = NULL;
		return (0);
	}
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i])
		data->path = ft_split(&envp[i][5], ':');
	if (data->path == NULL)
		return (-1);
	return (0);
}

t_arg_type	check_type(int i, int argc)
{
	t_arg_type	type;

	if (i == 1)
		type = infile;
	else if (i == argc - 1)
		type = outfile;
	else
		type = command;
	return (type);
}

int	parsing(char **argv, t_parse **argument, int argc, char **envp)
{
	int			i;
	t_parse		*new;

	i = 1;
	while (i < argc)
	{
		new = ft_node_new(argv[i], check_type(i, argc));
		if (new == NULL)
			return (ft_parse_clear(argument), -1);
		ft_node_add_back(argument, new);
		i++;
	}
	return (0);
	(void) envp;
}
