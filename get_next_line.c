/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:07:36 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/03/07 17:37:07 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		next_line(char **str, char **line, int fd)
{
	int		len;
	char	*basket;

	len = 0;
	while ((str[fd][len] != '\n') && (str[fd][len] != '\0'))
	{
		len++;
	}
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		basket = ft_strdup(str[fd] + len + 1);
		ft_strdel(&str[fd]);
		str[fd] = basket;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*temp;
	static char		*str[MAX_FD];
	char			buff[BUFF_SIZE + 1];
	int				res;

	if (fd < 0 || fd > MAX_FD || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		temp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if (ft_strchr(temp, '\n'))
			break ;
	}
	if (res == -1 || (res == 0 && (str[fd] == NULL || str[fd][0] == '\0')))
		return (res);
	return (next_line(str, line, fd));
}
