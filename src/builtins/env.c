/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <jlange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:25:51 by jlange            #+#    #+#             */
/*   Updated: 2018/01/17 14:55:46 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/sh21.h"
#include "../../inc/built_in.h"

static void		flag_i(char ***env)
{
	char **new_env;

	new_env = (char**)malloc(sizeof(char*) * 1);
	if (!new_env)
	{
		ft_perror("malloc", errno, NULL);
		exit(0);
	}
	new_env[0] = NULL;
	*env = ft_replace_env(new_env, *env);
}

static int		flag_u(char *str, char ***env, int *i)
{
	*i += 1;
	if (str)
		*env = ft_replace_env(ft_unsetenv(str, *env), *env);
	else
		return (-1);
	return (0);
}

static int		skip_flags(char **av, char ***env)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (av[++i] && av[i][0] == '-')
	{
		if (av[i][1] == '-' && av[i][2] == '0')
			return (i + 1);
		if (!ft_strcmp(av[i], "-i"))
			flag_i(env);
		else if (!ft_strcmp(av[i], "-u"))
			ret = flag_u(av[i + 1], env, &i);
		else
			return (-1);
		if (ret == -1)
			return (ret);
	}
	return (i);
}

static void		try_to_exec(t_cmd *cmd, char **av, char **env)
{
	char	**sav;
	char	**senv;

	sav = cmd->av;
	senv = ft_var_env(NULL);
	cmd->av = av;
	ft_var_env(env);
	ft_cmd(cmd);
	cmd->av = sav;
	ft_var_env(senv);
}

void			ft_env(t_cmd *cmd)
{
	char	**env;
	char	**av;
	int		ret;

	env = ft_cp_env(ft_var_env(NULL));
	ret = skip_flags(cmd->av, &env);
	if (ret == -1)
	{
		ft_putstr_fd("env [-i][name=value]... [-u name] \
				[utility [argument...]]\n", 2);
		free_tab_2d(env);
		ft_singleton(1, 1);
		return ;
	}
	ret += env_skip_name_value(&cmd->av[ret], &env);
	if (!cmd->av[ret])
	{
		ft_display_env(env);
		free_tab_2d(env);
		return ;
	}
	av = &cmd->av[ret];
	try_to_exec(cmd, av, env);
	free_tab_2d(env);
}
