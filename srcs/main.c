/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:19:58 by marine            #+#    #+#             */
/*   Updated: 2023/05/01 18:55:58 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int check_infile(char *argv, t_parse *argument)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return(write(2, "No such file or directory.\n", 27), -1);
	argument = malloc(sizeof(t_parse));
	if (argument == NULL)
		return (-1);
	argument->command = argv;
	argument->type = infile;
	argument->path = NULL;
	argument->fd = fd;
	return (0);
}

int check_commands(char **argv, t_parse *argument, int argc, char **envp)
{
	int i;
	i = 2;
	while (argv[i])
	{
		
		argument->next = malloc(sizeof(t_parse))
		// if (argument.next == NULL)
			//supprimer les maillons précédents
		argument = argument
		i++;
	}
}

int parsing(char **argv, t_parse *argument, int argc, char **envp)
{
	//checker infile
	if (check_infile(argv[1], argument) == -1)
		return (-1);
	//checker commandes
	
	//mettre outfile dans un maillon
}

int main(int argc, char **argv, char **envp)
{
	t_parse	argument;

	if (argc < 5)
		return (1);
	if (parsing(argv, &argument, argc, envp) == -1)
		return (1);
	
}