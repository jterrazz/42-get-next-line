/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:32:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/05/08 15:46:39 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// si static buff alors read du buff sinon read

int		join_line(char *str, char **line)
{
	char *line_sav;

	if (*line)
	{
		line_sav = *line;
		*line = ft_strjoin(*line, str);
		free(line_sav);
		free(str);
	}
	else
		*line = str;
	//check retur valuei
	if (*line == NULL)
		return (-1);
	return (0);
}

int		cpy_buffer(t_buff *buff, char **line)
{
	int i;
	char *str;
	char *line_sav;
	int ret;

	i = 0;
	ret = 0;
	str = ft_strnew(buff->buff_size);
	while (i < buff->buff_size)
	{
		if (!buff->buff[i] || buff->buff[i] == '\n')
		{
			ft_memmove(buff->buff, buff->buff + i, BUFF_SIZE - i);
			buff->buff_size = BUFF_SIZE - i;
			ret = 1;
			break ;
		}
		str[i] = buff->buff[i];
		i++;
	}
	join_line(str, line);
	return (ret);
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
	char *line;
	get_next_line(0, &line);
	ft_putstr(line);
return (0);
}
