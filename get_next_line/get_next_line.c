/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:24:48 by hjung             #+#    #+#             */
/*   Updated: 2020/06/04 23:29:27 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int			i;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*bckup = NULL;

	while ((rd_size = read(fd, buff, BUFFER_SIZE)))
	{
		i = 0;
		buff[rd_size] = '\0';
		if (bckup == NULL)
			bckup = ft_strdup(buff);
		else
			bckup = ft_strjoin(bckup, buff);
		while (bckup[i] != '\0')
		{
			if (bckup[i] == '\n')
			{
				*line = ft_substr(bckup, 0, i);
				bckup = &bckup[i + 1];
				return (1);
			}
			i++;
		}
	}
	if (*bckup != '\0')
	{
		*line = ft_strdup(bckup);
		*bckup = '\0';
		return (1);
	}
	else
		return (0);
}