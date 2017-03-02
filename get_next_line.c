/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:59:00 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/01 10:59:05 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libftprintf.h"

static char			*ft_extra(char *str, int fd)
{
	char	*str2;
	char	*strrendu;

	str2 = "";
	str[BUFF_SIZE] = '\0';
	get_next_line(fd, &str2);
	strrendu = ft_strjoin(str, str2);
	free(str2);
	return (strrendu);
}

int					get_next_line(const int fd, char **line)
{
	int		i;
	int		r;
	char	tmp[1];
	char	*str;

	i = 0;
	r = 1;
	tmp[0] = 'a';
	if (!(str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1))\
	|| !line || BUFF_SIZE < 1)
		return (-1);
	while (i < BUFF_SIZE && tmp[0] != '\0' && tmp[0] != '\n' && r == 1)
	{
		if ((r = read(fd, tmp, 1)) == -1)
			return (-1);
		str[i] = tmp[0];
		++i;
		if (i == BUFF_SIZE && tmp[0] != '\0' && tmp[0] != '\n' && r)
			str = ft_extra(str, fd);
	}
	if (tmp[0] == '\n' || r == 0)
		str[i - 1] = '\0';
	*line = str;
	return ((BUFF_SIZE > 1 && (i > 1 || tmp[0] == '\n')) ||\
	(BUFF_SIZE == 1 && r) ? 1 : 0);
}
