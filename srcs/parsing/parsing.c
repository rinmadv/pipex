/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:57:26 by marine            #+#    #+#             */
/*   Updated: 2023/07/10 00:12:58 by marine           ###   ########.fr       */
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
	if (!envp)
	{
		data->path = NULL;
		printf("env : %s", data->path[0]);
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

int	parsing(char **argv, t_parse **argument, int argc)
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
	// (void) envp; // pk si j'enlève envp ça me change tout alors que je l'utilise même pas dans ma fonction?
}
