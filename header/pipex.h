/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:30:55 by marine            #+#    #+#             */
/*   Updated: 2023/07/16 02:14:41 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdbool.h>
# include <sys/wait.h>

# define CMD 1
# define PERM 2
# define NOFILEDIR 3

typedef enum e_arg_type
{
	infile,
	outfile,
	command
}			t_arg_type;

typedef struct s_parse
{
	char				**command;
	t_arg_type			type;
	char				*path;
	int					fd;
	bool				first_cmd;
	bool				last_cmd;
	struct s_parse		*next;
}			t_parse;

typedef struct s_data
{
	char	**path;
	int		fd[2];
	int		here_doc;
	char	*delimiter;
	t_parse	*first_arg;
}			t_data;

/* Parsing */

int		parsing(char **argv, t_parse **argument, int argc, t_data *data);
int		parse_envp(t_data *data, char **envp);
char	**ft_split_space(char const *str);
void	check_first_lst_cmd(t_parse *arg);
int		heredoc(char *delimiter);
t_parse	*ft_node_new(char *argv, t_arg_type type, t_data *data);
t_parse	*ft_node_last(t_parse *node);
void	ft_node_add_back(t_parse **node, t_parse *new);
void	print_lst(t_parse *node);
void	ft_parse_del_one(t_parse *node);
void	ft_data_clear(t_data *data);
void	ft_parse_clear(t_parse **node);
void	ft_free_2d_array(char **path);

/* Executuion */

int		exec(t_data *data);
int		check_cmd(t_data *data, t_parse *current_arg);
void	redirect_infile(t_data *data, t_parse *arg);
void	redirect_outfile(t_data *data, t_parse *arg, int pipe_fd);
void	redirect_cmd(t_data *data, int pipe_fd);
void	redirection_error(int err, char *cmd, t_data *data);
int		print_err(int type, char *cmd);

#endif