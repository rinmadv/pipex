/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:30:55 by marine            #+#    #+#             */
/*   Updated: 2023/05/01 19:44:04 by marine           ###   ########.fr       */
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
	char		**command;
	t_arg_type	type;
	char		*path;
	int			fd;
	t_parse		*next;
}			t_parse;

//prototypes

#endif