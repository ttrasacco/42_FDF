/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:10:03 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/05 17:10:06 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_uitoa(uintmax_t n)
{
	char		*str;
	uintmax_t	tmp;
	uintmax_t	len;

	tmp = n;
	len = 0;
	while (tmp /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	str[len + 1] = '\0';
	while (n / 10)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len] = n + '0';
	return (str);
}
