/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:12:19 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:12:22 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_print_void_p(t_arg elem, intmax_t i, char *str)
{
	int		len;

	len = ft_get_ulen(str, &elem);
	str = ft_strnew(len);
	if (elem.preci != -2)
		ft_strcpy(str, ft_uitoa_base(i, "0123456789abcdef"));
	ft_put_before(str, '0', elem.preci - ft_strlen(str));
	ft_put_before(str, 'x', 1);
	ft_put_before(str, '0', 1);
	if (!elem.minus && !elem.zero)
		ft_put_before(str, ' ', elem.s_min - ft_strlen(str));
	if (!elem.minus && elem.zero)
		ft_put_after(str, '0', elem.s_min - ft_strlen(str));
	if (elem.minus)
		ft_put_after(str, ' ', elem.s_min - ft_strlen(str));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int			ft_print_p(t_arg elem, va_list *ap)
{
	intmax_t	i;
	char		*str;

	i = (intmax_t)va_arg(*ap, intmax_t);
	str = ft_uitoa_base(i, "0123456789abcdef");
	(elem.preci == 0 && i == 0 && (elem.preci -= 2)) ? str = "\0" : 0;
	return (ft_print_void_p(elem, i, str));
}
