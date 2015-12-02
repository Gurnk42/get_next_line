#include "get_next_line.h"

typedef struct		s_read
{
	char			*buf;
	int				fd;
	struct s_read	*next;
}					t_read;


//___1.2___
static t_read	*ft_search_lst(t_read **lst, int fd)
{
	ft_putstr("\nsearch");
	while (*lst)
	{
		ft_putstr("\nlst");
		if ((*lst)->fd == fd)
			break ;
		*lst = (*lst)->next;
	}
	return (*lst);
}

//___1.1___//
static t_read	*ft_newlst(char	*buf, int fd)
{
	t_read	*list;

	if (!(list = (t_read *)malloc(sizeof(*list))))
		return (NULL);
	if (!buf)
	{
		list->buf = NULL;
		list->fd = 0;
	}
	else
	{
		if (!(buf))
		{
			if (!(list->buf = ft_strnew(0)))
				return (NULL);
		}
		list->buf = buf;
		list->fd = fd;
	}
	list->next = NULL;
	return (list);
}

//___1___//
static t_read	*ft_ret_lst(int fd, char **line, t_read **lst)
{
	t_read *new;

	if (fd < 0 || !line)
	{
		ft_putstr("\nFD < 0 || line = NULL");
		return (NULL);
	}
	if (!(new = ft_search_lst(lst, fd)))
	{
		ft_putstr("\n!new");
		new = ft_newlst(ft_strnew(0), fd);
		new->next = *lst;
		*lst = new;
	}
	return (new);
}


//___2___//
static char	*ft_read_file(int *ret, t_read *lst, const int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	*ret = read(fd, buffer, BUFF_SIZE);
	buffer[*ret] = '\0';
	if ((lst->buf)[0] != '\0')
		tmp = ft_strjoin(lst->buf, buffer);
	else
		tmp = ft_strdup(buffer);
	ft_strclr(lst->buf);
	return (tmp);
}

int			get_next_line(int const fd, char **line)
{
	static t_read	*lst;
	int				ret;
	char			*cpy;
	char			*str;

	//DBG
	if (lst)
	{
		ft_putstr("\nlst buf : ");
		ft_putstr(lst->buf);
		ft_putstr("\nlst fd : ");
		ft_putnbr(lst->fd);
	}	
	if (lst->next != NULL)
	{
		ft_putstr("\nlst buf : ");
		ft_putstr(lst->next->buf);
		ft_putstr("\nlst fd : ");
		ft_putnbr(lst->next->fd);
	}


	if ((lst = ft_ret_lst(fd, line, &lst)) == NULL)
		return (-1);
	*line = ft_strnew(0);
	ret = 1;
	while (ret > 0)
	{
		cpy = ft_read_file(&ret, lst, fd);
		if ((str = ft_strchr(cpy, '\n')) != NULL)
		{
			*str = '\0';
			lst->buf = ft_strdup(str + 1);
			*line = ft_strjoin(*line, cpy);
			return (1);
		}
		*line = ft_strjoin(*line, cpy);
	}
	return (ret);
}
