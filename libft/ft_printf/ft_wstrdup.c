/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:54:38 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/03 11:54:40 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

wchar_t		*ft_wstrdup(wchar_t *src)
{
	wchar_t	*dest;
	int		i;

	i = 0;
	if (!(dest = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
