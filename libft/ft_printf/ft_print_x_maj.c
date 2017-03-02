/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:16:50 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:16:52 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_print_int_x_maj(t_arg elem, intmax_t i, char *str)
{
	int		len;
	int		nb;

	len = ft_get_ulen(str, &elem);
	str = ft_strnew(len);
	if (elem.preci != -2)
		ft_strcpy(str, ft_uitoa_base(i, "0123456789ABCDEF"));
	if (elem.preci != -3)
		elem.zero = 0;
	ft_put_before(str, '0', elem.preci - ft_strlen(str));
	nb = (elem.sharp && i > 0 ? len - ft_strlen(str) - 2 :\
	len - ft_strlen(str));
	if (elem.zero)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, '0', nb);
	elem.sharp && i > 0 ? ft_put_before(str, 'X', 1) : 0;
	elem.sharp && i > 0 ? ft_put_before(str, '0', 1) : 0;
	if (!elem.zero)
		elem.minus ? ft_put_after(str, ' ', nb) : ft_put_before(str, ' ', nb);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int			ft_print_x_maj(t_arg elem, va_list *ap)
{
	intmax_t	i;
	char		*str;

	if (elem.scd_flag == 0)
		i = (intmax_t)(unsigned char)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 1)
		i = (intmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 2)
		i = (intmax_t)va_arg(*ap, unsigned int);
	if (elem.scd_flag == 3)
		i = (intmax_t)va_arg(*ap, unsigned long int);
	if (elem.scd_flag == 4)
		i = (intmax_t)va_arg(*ap, unsigned long long int);
	if (elem.scd_flag == 5)
		i = (intmax_t)va_arg(*ap, intmax_t);
	str = ft_uitoa_base(i, "0123456789ABCDEF");
	(elem.preci == 0 && i == 0 && (elem.preci -= 2)) ? str = "\0" : 0;
	return (ft_print_int_x_maj(elem, i, str));
}
