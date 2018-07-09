/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_tilde.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <jlange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:22:40 by jlange            #+#    #+#             */
/*   Updated: 2018/01/17 14:55:59 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/sh21.h"

static char		*get_value(void)
{
	char *value;

	value = ft_getenv("HOME", ft_var_env(NULL));
	if (value)
	{
		while (*value != '=')
			++value;
		++value;
	}
	return (value);
}

void			ft_replace_tilde(t_shell *sh, int i)
{
	char	*str1;
	char	*value;
	char	*str2;

	str1 = ft_strndup(sh->line, i);
	value = get_value();
	str2 = ft_strdup(&sh->line[i + 1]);
	free(sh->line);
	sh->line = ft_replace_line(str1, value, str2);
	free(str1);
	free(str2);
}
