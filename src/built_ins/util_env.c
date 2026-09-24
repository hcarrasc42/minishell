/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:02:35 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:30:47 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_index(char **envp, char *key)
{
	int		i;
	int		key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, key_len) && envp[i][key_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	*build_env_str(char *key, char *value)
{
	char	*aux;
	char	*str;

	aux = ft_strjoin(key, "=");
	str = ft_strjoin(aux, value);
	free(aux);
	return (str);
}

char	**set_env(char **envp, char *key, char *value)
{
	char	*str;
	int		i;

	i = get_env_index(envp, key);
	if (i == -1)
	{
		str = build_env_str(key, value);
		envp = add_str_to_array(envp, str);
		free(str);
		return (envp);
	}
	free(envp[i]);
	envp[i] = build_env_str(key, value);
	return (envp);
}

char	*get_env(char **envp, char *key)
{
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], key, ft_strlen(key)))
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	*get_env_dup(char **envp, char *key)
{
	char	*value;

	if (!key || !*key)
		return (ft_strdup(""));
	if (!ft_strncmp(key, "?", 1))
		return (ft_itoa(g_exec_ret));
	value = get_env(envp, key);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}
