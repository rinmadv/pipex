/*	
check infile
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (write(2, "Permission denied\n", 18), -1);
	
		argument->fd = fd;

check outfile
	fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return (write(2, "Permission denied\n", 18), -1);

	argument->fd = fd;



int	check_infile(char *argv, t_parse *argument)
{
	int	fd;

	argument = malloc(sizeof(t_parse));
	if (argument == NULL)
		return (-1);
	argument->command = NULL;
	argument->type = infile;
	argument->path = argv;
	return (0);
}

int	check_outfile(char *argv, t_parse *argument)
{
	int	fd;

	argument = malloc(sizeof(t_parse));
	if (argument == NULL)
		return (-1);
	argument->command = NULL;
	argument->type = infile;
	argument->path = argv;
	ft_node_add_back(argument);
	return (0);
}

*/