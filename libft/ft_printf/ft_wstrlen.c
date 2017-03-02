/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:47:54 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/05 11:47:56 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_wstrlen(wchar_t *str)
{
	int		i;
	int		r;

	r = 0;
	i = -1;
	while (str[++i])
	{
		r += get_wchar_size(str[i]);
	}
	return (r);
}

int		get_wchar_size(wchar_t c)
{
	char	*str;
	int		i;
	int		r;

	str = ft_itoa_base((long long int)c, "01");
	i = 0;
	r = ft_strlen(str);
	r >= 0 && r <= 7 ? i = 1 : 0;
	r > 7 && r <= 11 ? i = 2 : 0;
	r > 11 && r <= 16 ? i = 3 : 0;
	r > 16 ? i = 4 : 0;
	return (i);
}
