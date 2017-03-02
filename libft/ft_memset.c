/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:13:15 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/05 13:13:17 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*b2;

	i = 0;
	b2 = (char *)b;
	while (i < n)
	{
		b2[i] = c;
		i++;
	}
	return (b2);
}