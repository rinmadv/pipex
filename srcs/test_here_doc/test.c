#include "pipex.h"

int main(int argc, char **argv)
{
	char *path;
	char *result;
	char *delimiter;
	(void) delimiter;

	if (argc != 3)
		return (0);
	delimiter = argv[2];

	/*test creation fichier*/
	if (strcmp(argv[1], "here_doc") != 0)
		return(0);
	path = ".goinfre/here_doc";
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("fd : %d\n", fd);
	if (fd < 0)
		return (-1);
		
	/*test gnl*/
	write(1,"hererdoc>", 10);
	result = ft_get_next_line(0);
	while (result)
	{
		if ((strlen(result) == (ft_strlen(delimiter) + 1)) && ft_strncmp(delimiter, result, (strlen(delimiter))) == 0)
		 	break;
		//printf("%s", result);
		write(fd, result, strlen(result));
		free(result);
		write(1,"hererdoc>", 10);
		result = ft_get_next_line(0);
	}
	printf("%s", result);
	free(result);
	return (0);
}

