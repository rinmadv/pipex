/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/02 02:19:41 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	parsing(char **argv, t_parse *argument, int argc, char **envp)
{
	int			i;
	t_parse		*new;

	i = 1;
	while (i < argc)
	{
		new = ft_node_new(argv[i], check_type(i, argc));
		if (new == NULL)
			return (ft_parse_clear(&argument), -1);
		ft_node_add_back(&argument, new);
		i++;
	}
	return (0);
	(void) envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_parse	*argument;

	argument = NULL;
	if (argc < 5)
		return (1);
	(void) envp;
	if (parsing(argv, argument, argc, envp) == -1)
		return (1);
	return (0);
}
