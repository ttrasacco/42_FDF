/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:00:13 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/12 14:00:15 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*ft_fill_wstr(char *str, char *bin, int len)
{
	int		i;

	i = 31;
	while (len > 0)
	{
		if (str[i] == '.')
		{
			str[i] = bin[--len];
			--i;
		}
		if (str[i] != '.')
			--i;
	}
	while (i >= 0)
	{
		if (str[i] == '.')
			str[i] = '0';
		--i;
	}
	return (str);
}

static char	*ft_apply_mask(int c)
{
	char	*str;
	char	*bin;
	int		i;

	i = -1;
	bin = ft_strdup(ft_itoa_base(c, "01"));
	if (!(str = (char *)malloc(sizeof(char) * 32)))
		return (NULL);
	while (str[++i])
		str[i] = '.';
	i = 0;
	if (ft_strlen(bin) > 0 && ft_strlen(bin) < 8)
		ft_strcpy(str, "........................0.......");
	else if (ft_strlen(bin) > 7 && ft_strlen(bin) < 12)
		ft_strcpy(str, "................110.....10......");
	else if (ft_strlen(bin) > 11 && ft_strlen(bin) < 17)
		ft_strcpy(str, "........1110....10......10......");
	else if (ft_strlen(bin) > 16 && ft_strlen(bin) < 22)
		ft_strcpy(str, "11110...10......10......10......");
	str = ft_fill_wstr(str, bin, ft_strlen(bin));
	return (str);
}

int			ft_putwchar(int c)
{
	int		i;
	int		j;
	int		r;
	int		tab[4];
	char	*str;

	str = ft_apply_mask(c);
	r = 0;
	i = -1;
	while (++i < 4)
		tab[i] = 0;
	i = -1;
	j = 128;
	while (++i < 32)
	{
		tab[i / 8] = tab[i / 8] + ((str[i] - '0') * j);
		j = (j == 1 ? 128 : j / 2);
	}
	i = -1;
	while (++i < 3)
		(tab[i] && ++r ? write(1, &tab[i], 1) : 0);
	++r;
	write(1, &tab[i], 1);
	return (r);
}
