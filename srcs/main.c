/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 04:03:04 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data)
{
	data->first_arg = NULL;
	data->here_doc = -1;
	data->delimiter = NULL;
	data->path = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_data(&data);
	if (argc < 5)
		return (1);
	if (parsing(argv, &data.first_arg, argc, &data) == -1)
		return (1);
	check_first_lst_cmd(data.first_arg);
	// while(data.first_arg)
	// {
	// 	dprintf(2, "cmd : %s, first arg : %d, last arg : %d\n", data.first_arg->command[0], data.first_arg->first_cmd, data.first_arg->last_cmd);
	// 	data.first_arg = data.first_arg->next;
	// }
	if (parse_envp(&data, envp) == -1)
		return (ft_data_clear(&data), 1);
	if (exec(&data) == -1)
		return (ft_data_clear(&data), 1);
	ft_data_clear(&data);
	return (0);
}
