/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:32:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/05/07 21:42:14 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE_H"
#include <fcntl.h>

// si static buff alors read du buff sinon read

int		get_next_line(const int fd, char **line)
{
	
}

// DELETE AT END !!!
int 	main(int argc, char *argv)
{
	char *line = "lolilol";
	int fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}
