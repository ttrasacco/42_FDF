/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:17:03 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:17:05 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_print_int_x(t_arg elem, intmax_t i, char *str)
{
	int		len;
	int		nb;

	len = ft_get_ulen(str, &elem);
	len = (elem.sharp && i > 0 && elem.s_min < len) ? len + 2 : len;
	str = ft_strnew(len);
	if (elem.preci != -2)
		ft_strcpy(str, ft_uitoa_base(i, "0123456789abcdef"));
	if (elem.preci != -3)
		elem.zero = 0;
	ft_put_before(str, '0', elem.preci - ft_strlen(str));
	nb = (elem.sharp && i > 0 ? len - ft_strlen(str) - 2 :\
	len - ft_strlen(str));
	if (elem.zero)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, '0', nb);
	elem.sharp && i > 0 ? ft_put_before(str, 'x', 1) : 0;
	elem.sharp && i > 0 ? ft_put_before(str, '0', 1) : 0;
	if (!elem.zero)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, ' ', nb);
	nb = ft_putstr(str);
	return (nb);
}

int			ft_print_x(t_arg elem, va_list *ap)
{
	uintmax_t	i;
	char		*str;

	if (elem.scd_flag == 0)
		i = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 1)
		i = (uintmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 2)
		i = (uintmax_t)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 3)
		i = (uintmax_t)va_arg(*ap, unsigned long int);
	if (elem.scd_flag == 4)
		i = (uintmax_t)va_arg(*ap, unsigned long long int);
	if (elem.scd_flag == 5)
		i = (uintmax_t)va_arg(*ap, uintmax_t);
	str = ft_uitoa_base(i, "0123456789abcdef");
	(elem.preci == 0 && i == 0 && (elem.preci -= 2)) ? str = "\0" : 0;
	return (ft_print_int_x(elem, i, str));
}
