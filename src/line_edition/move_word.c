/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:02:07 by vmartins          #+#    #+#             */
/*   Updated: 2018/01/22 19:02:39 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/line_edition.h"

void	ft_move_begin(t_lineterm *end, t_termc *tsh)
{
	if (tsh->auto_active)
		return ;
	if (end->prev)
	{
		while (end && end->index != 0)
		{
			end->s_pos = 0;
			if (end->next)
				end->next->s_pos = 0;
			end = end->prev;
		}
		tsh->line->last = 0;
		end = end->next;
	}
}

void	ft_move_end(t_lineterm *end, t_termc *tsh)
{
	if (tsh->auto_active)
		return ;
	if (end->next)
	{
		while (end)
		{
			end->s_pos = 1;
			if (end->prev && end->prev->index != 0)
				end->prev->s_pos = 0;
			end = end->next;
		}
		tsh->line->last = 1;
	}
}

void	ft_move_word_forward(t_lineterm *end, t_termc *tsh)
{
	if (tsh->auto_active)
		return ;
	while ((end->c == ' ' || end->c == '\t') && end && end->index != 0)
	{
		end->s_pos = 0;
		if (end->next)
			end->next->s_pos = 0;
		end = end->prev;
	}
	while (end->c != ' ' && end->c != '\t' && end && end->index != 0)
	{
		end->s_pos = 0;
		if (end->next)
			end->next->s_pos = 0;
		end = end->prev;
	}
	while (end && end->index != 0)
	{
		end->s_pos = 1;
		end = end->prev;
	}
	tsh->line->last = 0;
}

void	ft_move_word_back(t_lineterm *end, t_termc *tsh)
{
	if (tsh->auto_active)
		return ;
	while (end && ((char)end->c == ' ' || (char)end->c == '\n'))
	{
		end->s_pos = 1;
		if (end->prev && end->prev->index != 0)
			end->prev->s_pos = 0;
		end = end->next;
	}
	while (end && (char)end->c != ' ' && (char)end->c != '\n')
	{
		end->s_pos = 0;
		if (end->prev && end->prev->index != 0)
			end->prev->s_pos = 1;
		end = end->next;
	}
	while (end && ((char)end->c == ' ' || (char)end->c == '\n'))
	{
		end->s_pos = 1;
		if (end->prev && end->prev->index != 0)
			end->prev->s_pos = 0;
		end = end->next;
	}
}
