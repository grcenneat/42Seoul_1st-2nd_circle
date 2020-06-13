/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:24:48 by hjung             #+#    #+#             */
/*   Updated: 2020/06/14 06:36:20 by hjung            ###   ########.fr       */
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
	return (1);
}

int		ret_rest(char **bckup, char **line)
{
	int			i;

	if (*bckup == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (*bckup && (i = chk_nl_exist(*bckup)) >= 0)
		return (ret_line(bckup, line, i));
	else if (*bckup[0] != '\0')
	{
		*line = ft_strdup(*bckup);
		free(*bckup);
		*bckup = 0;
		return (0);
	}
	*line = ft_strdup("");
	free(*bckup);
	*bckup = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	ssize_t		rd_size;
	char		buff[BUFFER_SIZE + 1];
	static char	*bckup[OPEN_MAX];

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		bckup[fd] = gnl_strjoin(bckup[fd], buff);
		i = chk_nl_exist(bckup[fd]);
		if (i >= 0)
			return (ret_line(&bckup[fd], line, i));
	}
	if (rd_size < 0)
		return (-1);
	return (ret_rest(&bckup[fd], line));
}
