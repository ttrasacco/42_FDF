/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:33:57 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/21 13:33:59 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_tmp_next(t_arg *tmp)
{
	int		i;
	int		r;

	i = (tmp->type_conv == 14 ? 2 : 1);
	r = i;
	while (i > 0)
	{
		if (!(tmp->next = (t_arg *)malloc(sizeof(t_arg))))
			exit(1);
		tmp = tmp->next;
		--i;
	}
	return (r - 1);
}

void	ft_elem_next(t_arg *elem, int *n)
{
	int		i;

	i = (elem->type_conv == 14 ? 2 : 1);
	while (i > 0)
	{
		*elem = *elem->next;
		--*n;
		--i;
	}
}
