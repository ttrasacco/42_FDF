/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:03:36 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:03:38 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_s(t_arg elem, va_list *ap)
{
	return ((elem.scd_flag > 2) ? ft_print_s_maj(elem, ap) :\
	ft_print_s_min(elem, ap));
}

int		ft_print_s_min(t_arg elem, va_list *ap)
{
	char	*str;
	int		n;
	int		i;
	int		r;

	i = -1;
	r = 0;
	str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	n = (PRECI == -3 ? elem.s_min - ft_strlen(str) : s_to_print(str, elem));
	if (elem.minus == 0)
		while (n-- > 0 && ++r)
			ft_putchar(elem.zero == 1 ? '0' : ' ');
	if (PRECI != -3)
	{
		while (++i < PRECI && str[i] && ++r)
			ft_putchar(str[i]);
	}
	else
		r += ft_putstr(str);
	while (n-- > 0 && ++r)
		ft_putchar(' ');
	return (r);
}

int		s_to_print(char *str, t_arg elem)
{
	int		n;

	n = (elem.s_min > ft_strlen(str) ? elem.s_min - ft_strlen(str) : 0);
	if (n == 0)
		n = (elem.s_min > PRECI ? elem.s_min - PRECI : 0);
	else
		n = (PRECI < ft_strlen(str) ? n + ft_strlen(str) - PRECI : n);
	return (n);
}
