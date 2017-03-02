/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:17:29 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/12 22:17:31 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

wchar_t	*ft_wstrnew(int size)
{
	wchar_t	*str;
	int		i;

	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	str[size] = '\0';
	return (str);
}

int		ft_print_c_maj(t_arg elem, va_list *ap)
{
	char		*str;
	intmax_t	c;
	int			r;

	r = 0;
	c = (intmax_t)va_arg(*ap, long int);
	str = ft_strnew(elem.s_min > 0 ? elem.s_min : 1);
	if (elem.minus == 0)
	{
		ft_put_before(str, elem.zero ? '0' : ' ', elem.s_min - 1);
		write(1, str, ft_strlen(str));
	}
	r = ft_putwchar(c);
	if (elem.minus == 1)
	{
		ft_put_after(str, ' ', elem.s_min - 1);
		write(1, str, ft_strlen(str));
	}
	return (elem.s_min > 0 ? elem.s_min - 1 + r : r);
}
