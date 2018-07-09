/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:47:59 by vmartins          #+#    #+#             */
/*   Updated: 2018/01/24 18:48:13 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_reverse(char *str)
{
	int	i;
	int	j;

	j = ft_strlen(str);
	i = 0;
	while (i < j / 2)
	{
		ft_swap(&str[i], &str[j - i - 1]);
		i++;
	}
	return (str);
}
