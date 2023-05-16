/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:30:55 by marine            #+#    #+#             */
/*   Updated: 2023/05/16 14:23:14 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//include 
# include "libft.h"

//defines

//typedefs
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
	struct s_parse		*next;
}			t_parse;

typedef struct s_data
{
	char	**path;
	t_parse	*first_arg;
}			t_data;

/* Parsing - liste chainees arguments */
t_parse	*ft_node_new(char *argv, t_arg_type type);
t_parse	*ft_node_last(t_parse *node);
void	ft_node_add_back(t_parse **node, t_parse *new);
void	print_lst(t_parse *node);

/* Parsing - free liste chainees arguments */
void	ft_parse_del_one(t_parse *node);
void	ft_data_clear(t_data *data);
void	ft_parse_clear(t_parse **node);
void	ft_free_2d_array(char **path);

/* Parsing - autre */
int		parsing(char **argv, t_parse **argument, int argc, char **envp);
int		parse_envp(t_data *data, char **envp);
char	**ft_split_space(char const *str);

/* Executuion */
int		exec(t_data *data);

/* Check files */
int		check_infile(t_parse *argument);
int		check_outfile(t_parse *argument);

#endif