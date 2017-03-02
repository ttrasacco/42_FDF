/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:17:19 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:17:21 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_print_c(t_arg elem, va_list *ap)
{
	return ((elem.scd_flag > 2) ? ft_print_c_maj(elem, ap) :\
	ft_print_c_min(elem, ap));
}

int		ft_print_c_min(t_arg elem, va_list *ap)
{
	char		*str;
	intmax_t	c;
	int			r;

	r = 0;
	c = (intmax_t)(char)va_arg(*ap, int);
	str = ft_strnew(elem.s_min > 0 ? elem.s_min : 1);
	if (elem.minus == 0)
	{
		ft_put_before(str, elem.zero ? '0' : ' ', elem.s_min - 1);
		write(1, str, ft_strlen(str));
	}
	r = ft_putchar(c);
	if (elem.minus == 1)
	{
		ft_put_after(str, ' ', elem.s_min - 1);
		write(1, str, ft_strlen(str));
	}
	return (elem.s_min > 0 ? elem.s_min - 1 + r : r);
}
