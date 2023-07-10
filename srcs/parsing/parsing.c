/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:57:26 by marine            #+#    #+#             */
/*   Updated: 2023/07/11 00:01:55 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_first_lst_cmd(t_parse *arg)
{
	arg = arg->next;
	arg->first_cmd = true;
	while (arg->next->type != outfile)
		arg = arg->next;
	arg->last_cmd = true;
}

int	parse_envp(t_data *data, char **envp)
{
	int		i;

	i = 0;
	if (!envp[0])
		return (0);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i])
		data->path = ft_split(&envp[i][5], ':');
	if (data->path == NULL)
		return (-1);
	return (0);
}

t_arg_type	check_type(int i, int argc, char *argv)
{
	t_arg_type	type;

	if (i == 1)
	{
		if (ft_strncmp(argv, "here_doc", 8) == 0)
			type = heredoc;
		else
			type = infile;
	}
	else if (i == argc - 1)
		type = outfile;
	else
		type = command;
	return (type);
}

int	parsing(char **argv, t_parse **argument, int argc, t_data *data)
{
	int			i;
	t_parse		*new;
	t_arg_type	type;

	i = 1;
	while (i < argc)
	{
		type = check_type(i, argc, argv[i]);
		if (type == heredoc)
		{
			i++;
			data->here_doc = 1;
		}
		new = ft_node_new(argv[i], type);
		if (new == NULL)
			return (ft_parse_clear(argument), -1);
		ft_node_add_back(argument, new);
		i++;
	}
	return (0);
}
