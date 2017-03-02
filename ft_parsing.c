/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:21:40 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/01 15:57:24 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_fill_coor(t_point *tmp, char **tab)
{
	int			i;
	int			j;
	static int	nbr_y = 0;

	i = 0;
	j = 0;
	while (tab[i])
	{
		tmp->x = i;
		tmp->y = nbr_y;
		tmp->z = (tab[i][0] == '.') ? NO_PIXEL : ft_atoi(tab[i]);
		tmp->c = ft_get_color(tmp);
		if (!(tmp->next = (t_point *)malloc(sizeof(t_point))))
			exit(1);
		tmp = tmp->next;
		++i;
	}
	++nbr_y;
	return (tmp);
}

t_point	*ft_parsing(int fd)
{
	t_point	*list;
	t_point	*tmp;
	char	*line;
	char	**tab;
	int		i;

	i = -1;
	if (!(tmp = (t_point *)malloc(sizeof(t_point))))
		exit(1);
	list = tmp;
	while (get_next_line(fd, &line) && (i = -1))
	{
		while (line[++i])
			if (!ft_isdigit(line[i]) && !IS_SPACE(line[i]))
				exit(write(1, "INVALID FILE\n", 13));
		tab = ft_strsplit(line, ' ');
		tmp = ft_fill_coor(tmp, tab);
	}
	tmp->next = NULL;
	return (list);
}

int		ft_mini_ls(struct dirent *map, DIR *maps_dir, int *j)
{
	int		i;

	i = 1;
	if (maps_dir == NULL)
	{
		ft_printf("ERROR : INVALID OR EMPTY ARGUMENT\n");
		exit(1);
	}
	while ((map = readdir(maps_dir)) != NULL)
	{
		if (ft_strcmp(map->d_name, ".") != 0 && \
		ft_strcmp(map->d_name, "..") != 0)
		{
			printf("(%d) - %s\n", i, map->d_name);
			++i;
		}
	}
	ft_printf("\nselect the file to open : ");
	scanf("%d", j);
	return (i);
}

t_point	*ft_parsing_dir(char *str)
{
	DIR				*maps_dir;
	struct dirent	*map;
	int				fd_f;
	int				i;
	int				j;

	j = 0;
	map = NULL;
	str = ft_strjoin(str, "/");
	maps_dir = opendir(str);
	i = ft_mini_ls(map, maps_dir, &j);
	if (j > 0 && j <= i + 3)
	{
		rewinddir(maps_dir);
		while (--j + 3 > 0)
			map = readdir(maps_dir);
		i = telldir(maps_dir);
		seekdir(maps_dir, i);
		if (ft_strchr(map->d_name, '.') != NULL)
		{
			fd_f = open(ft_strjoin(str, map->d_name), O_RDONLY);
			return (ft_parsing(fd_f));
		}
	}
	exit(0);
}
