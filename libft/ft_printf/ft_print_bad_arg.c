/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bad_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:33:42 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/23 17:33:44 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_bad_arg(t_arg elem)
{
	int		i;
	char	*str;
	int		len;

	str = ft_strnew(elem.s_min > 0 ? elem.s_min : 1);
	str[0] = (char)elem.type_conv;
	i = elem.s_min - 1;
	if (elem.minus == 0)
		ft_put_before(str, elem.zero ? '0' : ' ', i);
	if (elem.minus == 1)
		ft_put_after(str, ' ', i);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
