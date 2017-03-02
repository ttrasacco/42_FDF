/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:16:15 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:16:17 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_print_o_maj(t_arg elem, va_list *ap)
{
	int			len;
	int			nb;
	char		*tmp;
	char		*str;
	intmax_t	i;

	i = (intmax_t)va_arg(*ap, unsigned long int);
	tmp = ft_strdup(ft_uitoa_base(i, "01234567"));
	len = ft_get_ulen(tmp, &elem);
	str = ft_strnew(len);
	(elem.preci == 0 && i == 0 && (elem.preci -= 2)) ? 0 : ft_strcpy(str, tmp);
	if (elem.preci != -3)
		elem.zero = 0;
	ft_put_before(str, '0', elem.preci - ft_strlen(str));
	nb = elem.sharp ? len - ft_strlen(str) - 1 : len - ft_strlen(str);
	if (elem.zero && elem.s_min > elem.preci)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, '0', nb);
	(elem.sharp && i > 0) || (elem.sharp && elem.preci == -2) ?\
	ft_put_before(str, '0', 1) : 0;
	if (!elem.zero && elem.s_min > elem.preci)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, ' ', nb);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
