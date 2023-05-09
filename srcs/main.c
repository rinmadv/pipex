/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/09 14:45:07 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.first_arg = NULL;
	if (argc < 5)
		return (1);
	(void) envp;
	if (parsing(argv, &data.first_arg, argc, envp) == -1)
		return (1);
	if (parse_envp(&data, envp) == -1)
		return (ft_data_clear(&data), 1);
	if (exec(&data) == -1)
		return (ft_data_clear(&data), 1);
	ft_data_clear(&data);
	return (0);
}

	// print_lst(data.first_arg);
