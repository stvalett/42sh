/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_opendir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:41:34 by vmartins          #+#    #+#             */
/*   Updated: 2018/01/24 18:41:55 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <dirent.h>

int	ft_count_opendir(char *str)
{
	int				count;
	DIR				*path;
	struct dirent	*file;

	count = 0;
	if ((path = opendir(str)) != NULL)
	{
		while ((file = readdir(path)) != NULL)
			count++;
		closedir(path);
	}
	return (count);
}
