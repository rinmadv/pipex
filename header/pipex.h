/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:30:55 by marine            #+#    #+#             */
/*   Updated: 2023/05/02 02:21:44 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//defines
# include "../libft/libft.h"

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

/* Parsing - arguments */
t_parse	*ft_node_new(char *argv, t_arg_type type);
t_parse	*ft_node_last(t_parse *node);
void	ft_node_add_back(t_parse **node, t_parse *new);
void	ft_parse_del_one(t_parse *node);
void	ft_parse_clear(t_parse **node);

/* Parsing - autre */
char	**ft_split_space(char const *str);

//executions

#endif