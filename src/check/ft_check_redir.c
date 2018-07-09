/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:18:57 by vmartins          #+#    #+#             */
/*   Updated: 2018/01/23 15:53:35 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/sh21.h"
#include "../../inc/quote.h"

static	int		check_token(char *line)
{
	int	ret;

	ret = 0;
	ret = (line[0] == '>') ? 1 : ret;
	ret = (line[0] == '<') ? 2 : ret;
	ret = (line[0] == '>' && line[1] == '&') ? 3 : ret;
	ret = (line[0] == '>' && line[1] == '>') ? 4 : ret;
	ret = (line[0] == '<' && line[1] == '&') ? 5 : ret;
	ret = (line[0] == '<' && line[1] == '<') ? 6 : ret;
	ret = (line[0] == '<' && line[1] == '>') ? 7 : ret;
	return (ret);
}

static	int		check_next_token(char *line)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	i += ft_skip_useless(line);
	ret = (line[i] == '\n' || line[i] == 0) ? 1 : ret;
	ret = (line[i] == ';') ? 2 : ret;
	ret = (line[i] == '&') ? 3 : ret;
	ret = (line[i] == '|') ? 4 : ret;
	ret = (line[i] == '>') ? 5 : ret;
	ret = (line[i] == '<') ? 6 : ret;
	ret = (line[i] == '|' && line[i + 1] == '|') ? 7 : ret;
	ret = (line[i] == '&' && line[i + 1] == '&') ? 8 : ret;
	ret = (line[i] == '>' && line[i + 1] == '&') ? 9 : ret;
	ret = (line[i] == '>' && line[i + 1] == '>') ? 10 : ret;
	ret = (line[i] == '<' && line[i + 1] == '&') ? 11 : ret;
	ret = (line[i] == '<' && line[i + 1] == '<') ? 12 : ret;
	ret = (line[i] == '<' && line[i + 1] == '>') ? 13 : ret;
	return (ret);
}

static void		print_error2(int token)
{
	if (token == 8)
		write(2, "&&", 2);
	else if (token == 9)
		write(2, ">&", 2);
	else if (token == 10)
		write(2, ">>", 2);
	else if (token == 11)
		write(2, "<&", 2);
	else if (token == 12)
		write(2, "<<", 2);
	else if (token == 13)
		write(2, "<>", 2);
}

static	void	print_error(int token)
{
	write(2, "42sh: syntax error near unexpected token `", 42);
	if (token == 1)
		write(2, "\\n", 2);
	else if (token == 2)
		write(2, ";", 1);
	else if (token == 3)
		write(2, "&", 1);
	else if (token == 4)
		write(2, "|", 1);
	else if (token == 5)
		write(2, ">", 1);
	else if (token == 6)
		write(2, "<", 1);
	else if (token == 7)
		write(2, "||", 2);
	else
		print_error2(token);
	write(2, "'\n", 2);
}

int				ft_check_redir(t_shell *sh)
{
	int			i;
	int			op;
	int			token;

	i = 0;
	while (sh->line[i])
	{
		i += ft_skip_quote(&sh->line[i]);
		i += ft_skip_dquote(&sh->line[i]);
		if ((op = check_token(&sh->line[i])))
		{
			token = check_next_token(&sh->line[i + ((op > 2) ? 2 : 1)]);
			if (token)
			{
				print_error(token);
				return (1);
			}
		}
		if (ft_backslash_word(&sh->line[i]) > 0)
			i++;
		i++;
	}
	return (0);
}
