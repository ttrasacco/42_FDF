/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:16:38 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:16:40 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_u_maj(t_arg elem, va_list *ap)
{
	long unsigned int	i;
	int					n;
	int					j;
	char				*str;

	i = va_arg(*ap, long unsigned int);
	str = ft_uitoa((uintmax_t)i);
	j = (PRECI > ft_strlen(str) ? PRECI - ft_strlen(str) : 0);
	n = SMIN - ft_strlen(str) - j + 1;
	while (!elem.minus && --n > 0)
		ft_putchar(PRECI == -3 && ZERO ? '0' : ' ');
	while (j-- > 0)
		ft_putchar('0');
	ft_putstr(str);
	while (--n > 0)
		ft_putchar(' ');
	n = ft_strlen(str);
	free(str);
	return ((elem.s_min - n) < 0 ? n : elem.s_min);
}
