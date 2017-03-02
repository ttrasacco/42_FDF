/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:15:49 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:15:50 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_print_int_i(t_arg elem, intmax_t i, char *str)
{
	int		len;

	len = ft_get_len(str, &elem, i >= 0 ? 1 : -1);
	str = ft_strnew(len);
	if (elem.preci != -2)
	{
		ft_strcpy(str, ft_itoa((i >= 0 ? i : -i)));
		i == (-9223372036854775807 - 1) ? ft_strcpy(str, INT_MAX_MAX) : 0;
	}
	if (elem.preci != -3)
		elem.zero = 0;
	ft_put_before(str, '0', elem.preci - ft_strlen(str));
	if (elem.zero)
		elem.minus ?\
		ft_put_after(str, ' ', len - ft_strlen(str) - SIGN_OR_NOT)\
		: ft_put_before(str, '0', len - ft_strlen(str) - SIGN_OR_NOT);
	(i >= 0 && elem.plus) ? ft_put_before(str, '+', 1) : 0;
	(i < 0) ? ft_put_before(str, '-', 1) : 0;
	(i > 0 && !elem.plus && elem.space) ? ft_put_before(str, ' ', 1) : 0;
	if (!elem.zero)
		elem.minus ?\
	ft_put_after(str, ' ', len - ft_strlen(str))\
	: ft_put_before(str, ' ', len - ft_strlen(str));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int			ft_print_i(t_arg elem, va_list *ap)
{
	intmax_t	i;
	char		*str;

	if (elem.scd_flag == 0)
		i = (intmax_t)(char)va_arg(*ap, int);
	if (elem.scd_flag == 1)
		i = (intmax_t)(short int)va_arg(*ap, int);
	if (elem.scd_flag == 2)
		i = (intmax_t)va_arg(*ap, int);
	if (elem.scd_flag == 3)
		i = (intmax_t)va_arg(*ap, long int);
	if (elem.scd_flag == 4)
		i = (intmax_t)va_arg(*ap, long long int);
	if (elem.scd_flag == 5)
		i = (intmax_t)va_arg(*ap, intmax_t);
	str = ft_itoa_base(i < 0 ? -(intmax_t)i : (intmax_t)i, "0123456789");
	if ((elem.scd_flag == 4 || elem.scd_flag == 5)
		&& i == -9223372036854775807 - 1)
		str = "9223372036854775808";
	(elem.preci == 0 && i == 0 && (elem.preci -= 2)) ? str = "\0" : 0;
	return (ft_print_int_i(elem, i, str));
}
