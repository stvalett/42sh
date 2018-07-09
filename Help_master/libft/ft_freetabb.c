/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:54:10 by vmartins          #+#    #+#             */
/*   Updated: 2017/05/22 15:54:11 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetabb(char ***tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_freetab(&tab[i]);
	free(tab);
	tab = NULL;
}