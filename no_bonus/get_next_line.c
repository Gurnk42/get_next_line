/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:18:00 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/18 13:41:34 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int *ret, char *buf, const int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	char	*tmp2;

	*ret = read(fd, buffer, BUFF_SIZE);
	buffer[*ret] = '\0';
		tmp2 = buffer;
	if (buf[0] != '\0')
		tmp = ft_strjoin(buf, buffer);
	else
		tmp = ft_strdup((const char *)buffer);
	ft_strclr(buf);
	ft_memdel((void **)&buf);
	return (tmp);
}

static int	ft_gnl_loop(const int fd, char ***line, int *ret, char **buf)
{
	char			*str;
	char	*cpy;

	cpy = read_file(ret, *buf, fd);
	if ((str = ft_strchr(cpy, '\n')) != NULL)
	{
		*str = '\0';
		*buf = ft_strdup(str + 1);
		**line = ft_strjoin(**line, cpy);
		ft_memdel((void **)&cpy);
		return (1);
	}
	**line = ft_strjoin(**line, cpy);
	ft_memdel((void **)&cpy);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		if (ft_gnl_loop(fd, &line, &ret, &buf) == 1)
			return (1);
	}
	return (ret);
}
