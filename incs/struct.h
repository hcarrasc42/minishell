/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/02/23 16:39:50 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pipex
{
	pid_t	pid;
	int		len;
	int		**fd;
	int		fdin;
	int		fdout;
	char	*path;
	char	**cmd;
	char	***spl;
}		t_pipex;

typedef struct s_split
{
	int		i;
	int		j;
	int		k;
	int		y;
	int		com;
	int		len;
	int		val;
	int		ft_len;
	char	*str;
	char	*read;
	char	**tmp;
}	t_split;

typedef struct s_data
{
	int		in;
	int		out;
	int		val;
	int		input;
	int		output;
	char	*infile;
	char	*outfile;
}	t_data;

typedef struct s_path
{
	char	*path;
}	t_path;

#endif