/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:05 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/27 13:06:20 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_split
{
	int		i;
	int		j;
	int		y;
	int		k;
	int		com;
	int		len;
	int		ft_len;
	char	*read;
	char	**tmp;
}	t_split;

#endif