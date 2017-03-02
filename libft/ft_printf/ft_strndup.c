/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:01:34 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/06 18:01:36 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_strndup(char *src, int i)
{
	char	*dest;
	int		n;

	n = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
		dest[n++] = src[i++];
	dest[n] = '\0';
	return (dest);
}
