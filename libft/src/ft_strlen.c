/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:23:57 by vmartins          #+#    #+#             */
/*   Updated: 2018/01/24 18:49:49 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}
