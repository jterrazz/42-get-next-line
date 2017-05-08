/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:32:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/05/08 14:00:26 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// si static buff alors read du buff sinon read

int		cpy_buffer(t_buff *buff, char **line)
{
	int i;

	i = 0;
	while (i < buff->buff_size)
	{
		if (!buff->buff[i] || buff->buff[i] == '\n')
		{
			ft_memmove(buff->buff, buff->buff + i, BUFF_SIZE - i);
			buff->buff_size = BUFF_SIZE - i;
			return (1);
		}
		**line = buff->buff[i];
		ft_putchar(buff->buff[i]);
		(*line)++;
		**line = 0;
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static t_buff	buff;
	int res;

	ret = 0;
	res = 0;
	if ((&buff)->buff_size > 0 && cpy_buffer((&buff), line))
		return (1);
	while (!res)
	{
		ret = read(fd, (&buff)->buff, BUFF_SIZE);
		(&buff)->buff_size = ret;
		if (ret < 0)
			return (-1);
		else if (!ret)
			return (0);
		res = cpy_buffer((&buff), line);
	}
	return (1);
}

// DELETE AT END !!!
int 	main(int argc, char **argv)
{
	char *line = ft_strdup("lgjoeihiogjioergjwefnweiofbwuepbgwegnerkgnekjbgdfhkvbsodk;vjdfhlbnegiojaerbvliuaejrvnea'porkvbeargjerkgjeiraogearbgue;orijgeporgnkelsjbvouebljherkgfoperjkgnerogberng;jekrbnvdflbnkd");
	get_next_line(0, &line);
	return (0);
}
