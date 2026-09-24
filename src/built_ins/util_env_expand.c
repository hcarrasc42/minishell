/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruramire <ruramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:24:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/06/21 09:31:29 by ruramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_aux(char *str, t_exp *exp, t_mini *state)
{
	exp->name = ft_substr(str, exp->index_dollar, exp->i - exp->index_dollar);
	exp->end = ft_substr(str, exp->i, ft_strlen(&str[exp->i]));
	exp->value = get_env_dup(state->envp, exp->name + 1);
	free(exp->name);
	exp->aux = join_and_free(exp->start, exp->value);
}

char	*expand_env_str(char *str, t_mini *state)
{
	t_exp	exp;

	exp.i = 0;
	if (!ft_strchr(str, '$'))
		return (str);
	while (str && str[exp.i] != '$')
		exp.i++;
	exp.start = ft_substr(str, 0, exp.i);
	exp.index_dollar = exp.i++;
	while (ft_isalnum(str[exp.i]) || str[exp.i] == '_' || str[exp.i] == '?')
	{
		if (str[exp.i] == '?' && str[exp.i + 1] == '?')
		{
			exp.i++;
			break ;
		}
		exp.i++;
	}
	expand_aux(str, &exp, state);
	exp.final = join_and_free(exp.aux, exp.end);
	free(str);
	return (exp.final);
}
