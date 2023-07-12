/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/07/12 15:37:19 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.first_arg = NULL;
	data.here_doc = -1;
	data.path = NULL;
	if (argc < 5)
		return (1);
	if (parsing(argv, &data.first_arg, argc, &data) == -1)
		return (1);
	check_first_lst_cmd(data.first_arg);
	if (data.here_doc == 1)
		get_here_doc_text()
	if (parse_envp(&data, envp) == -1)
		return (ft_data_clear(&data), 1);
	// print_lst(data.first_arg);
	if (exec(&data) == -1)
	 	return (ft_data_clear(&data), 1);
	ft_data_clear(&data);
	return (0);
}