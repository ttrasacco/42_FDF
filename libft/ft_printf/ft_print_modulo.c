/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modulo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:15:49 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:15:50 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_modulo(t_arg elem)
{
	int		i;
	char	*str;
	int		len;

	str = ft_strnew(elem.s_min > 0 ? elem.s_min : 1);
	str[0] = '%';
	i = elem.s_min - 1;
	if (elem.minus == 0)
		ft_put_before(str, elem.zero ? '0' : ' ', i);
	if (elem.minus == 1)
		ft_put_after(str, ' ', i);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
