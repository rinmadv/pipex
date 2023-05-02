/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/02 19:29:15 by madavid          ###   ########.fr       */
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
	if (parsing(argv, data.first_arg, argc, envp) == -1)
		return (1);
	if (parse_envp(&data, envp) == -1)
		return (ft_parse_clear(&data.first_arg), 1);
	// printf("argument = %s", argument->command[0]);
	ft_parse_clear(&data.first_arg);
	return (0);
}
