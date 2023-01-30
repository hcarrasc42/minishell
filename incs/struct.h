/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/30 10:15:20 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_split
{
	int		i;
	int		j;
	int		k;
	int		y;
	int		com;
	int		len;
	int		ft_len;
	char	*read;
	char	**tmp;
}	t_split;

typedef struct s_pipex
{
	int		input;
	int		output;
}	t_pipex;

#endif