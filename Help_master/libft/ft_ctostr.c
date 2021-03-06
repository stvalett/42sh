/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:52:52 by vmartins          #+#    #+#             */
/*   Updated: 2017/06/06 11:03:20 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctostr(char c)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * (2))))
		return (0);
	new[0] = c;
	new[1] = '\0';
	return (new);
}
