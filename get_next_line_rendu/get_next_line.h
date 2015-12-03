/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <ebouther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:14:30 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/03 15:14:35 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct		s_read
{
	char			*buf;
	int				fd;
	struct s_read	*next;
}					t_read;

int					get_next_line(int const fd, char **line);

#endif
