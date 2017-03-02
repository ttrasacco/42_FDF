/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:46:10 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/16 22:46:12 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_get_len(char *str, t_arg *elem, int sign)
{
	int i;
	int r;
	int len;

	len = ft_strlen(str);
	r = (elem->plus || elem->space || sign == -1) ? 1 : 0;
	i = elem->s_min > (len + r) ? elem->s_min : (len + r);
	i = (elem->preci + r) > i ? (elem->preci + r) : i;
	return (i);
}

int		ft_get_ulen(char *str, t_arg *elem)
{
	int i;
	int len;

	len = ft_strlen(str);
	len = (str[0] == '0' && ft_strlen(str) == 1 ? 0 : len);
	i = elem->s_min > len ? elem->s_min : len;
	i = elem->preci > i ? elem->preci : i;
	return (i);
}

void	ft_put_after(char *nbr, char c, int n)
{
	int		len;

	len = ft_strlen(nbr);
	while (n-- > 0)
		nbr[len++] = c;
}

void	ft_put_before(char *str, char c, int nb)
{
	int		i;
	char	tmp;

	while (nb > 0)
	{
		i = ft_strlen(str);
		while (i-- > 0)
		{
			tmp = str[i];
			str[i + 1] = tmp;
		}
		str[0] = c;
		--nb;
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
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
