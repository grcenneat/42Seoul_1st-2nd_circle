/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:24:48 by hjung             #+#    #+#             */
/*   Updated: 2020/06/09 22:46:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chk_nl_exist(char *bckup)
{
	int			i;

	i = 0;
	while (bckup[i] != '\0')
	{
		if (bckup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ret_line(char **bckup, char **line, int i)
{
	char		*tmp_ptr;

	*line = ft_substr(*bckup, 0, i);
	tmp_ptr = ft_strdup(&(*bckup)[i + 1]);
	free(*bckup);
	*bckup = tmp_ptr;
	/*
	if ((*bckup)[0] == '\0')
	{
		free(*bckup);
		return (0);
	}*/
	return (1);
}

int		ret_rest(char **bckup, char **line, ssize_t rd_size)
{
	if (rd_size == 0 && bckup == 0)
	{
		printf("First block excuted\n");
		*line=ft_strdup("");
		return (1);
	}
	else if (rd_size == 0 && (*bckup)[0] == '\0')
	{
		printf("Second block excuted\n");
		free(*bckup);
		return (0);
	}
	else if ((*bckup)[0] != '\0')
	{
		printf("Third block excuted\n");
		*line = ft_strdup(*bckup);
		free(*bckup);
		*bckup = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*bckup[FOPEN_MAX];

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		bckup[fd] = ft_strjoin(bckup[fd], buff);
		i = chk_nl_exist(bckup[fd]);
		if (i >= 0)
			return (ret_line(&bckup[fd], line, i));
	}
	return (ret_rest(&bckup[fd], line, rd_size));
}
