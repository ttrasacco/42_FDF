/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:12:02 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:12:05 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_s_maj(t_arg elem, va_list *ap)
{
	wchar_t *str;
	int		i;
	int		tmp;
	int		c;

	c = 0;
	tmp = elem.preci;
	i = -1;
	str = va_arg(*ap, wchar_t*);
	str == NULL ? str = L"(null)" : 0;
	while (str[++i] && (elem.preci == -3 || (elem.preci != -3 &&\
	(tmp -= get_wchar_size(str[i])) >= 0)))
		c += get_wchar_size(str[i]);
	elem.s_min -= c;
	c = 0;
	while (!elem.minus && (--elem.s_min >= 0) && ++c)
		ft_putchar(elem.zero ? '0' : ' ');
	i = -1;
	while (str[++i] && (elem.preci == -3 || (elem.preci != -3 &&\
	(elem.preci -= get_wchar_size(str[i])) >= 0)))
		c += ft_putwchar(str[i]);
	while (elem.minus && (--elem.s_min >= 0) && ++c)
		ft_putchar(elem.zero ? '0' : ' ');
	return (c);
}

int		ws_to_print(wchar_t *str, t_arg elem)
{
	int		n;
	int		len;

	len = ft_wstrlen(str);
	n = (elem.s_min > len ? elem.s_min - len : 0);
	if (n == 0)
		n = (elem.s_min > PRECI ? elem.s_min - PRECI : 0);
	else
		n = (PRECI < len ? n + len - PRECI : n);
	return (n);
}
