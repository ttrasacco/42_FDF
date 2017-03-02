/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:35:09 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/06 17:35:11 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_tab_functions(t_arg *elem, va_list *ap)
{
	static int	init = 0;
	static int	(*tab_functions[14])(t_arg elem, va_list *ap);

	if (init == 0)
	{
		tab_functions[0] = ft_print_s;
		tab_functions[1] = ft_print_s_maj;
		tab_functions[2] = ft_print_p;
		tab_functions[3] = ft_print_d;
		tab_functions[4] = ft_print_d_maj;
		tab_functions[5] = ft_print_i;
		tab_functions[6] = ft_print_o;
		tab_functions[7] = ft_print_o_maj;
		tab_functions[8] = ft_print_u;
		tab_functions[9] = ft_print_u_maj;
		tab_functions[10] = ft_print_x;
		tab_functions[11] = ft_print_x_maj;
		tab_functions[12] = ft_print_c;
		tab_functions[13] = ft_print_c_maj;
	}
	init = 1;
	return ((tab_functions[elem->type_conv])(*elem, ap));
}
