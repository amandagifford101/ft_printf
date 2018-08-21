/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:07:30 by agifford          #+#    #+#             */
/*   Updated: 2018/08/21 15:04:50 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_out(t_components *m)
{
	if (CHECK_S(m->e_flags))
		string_it(m);
	else if (CHECK_SS(m->e_flags))
		p_widestring(m);
	else if (CHECK_P(m->e_flags))
		p_pointer(m);
	else if (CHECK_D(m->e_flags) || CHECK_DD(m->e_flags) || CHECK_I(m->e_flags))
		p_decimal(m);
	else if (CHECK_O(m->e_flags) || CHECK_OO(m->e_flags))
		p_octal(m);
	else if (CHECK_U(m->e_flags) || CHECK_UU(m->e_flags))
		p_undecimal(m);
	else if (CHECK_X(m->e_flags) || CHECK_XX(m->e_flags))
		p_hex(m);
	else if (CHECK_C(m->e_flags) || CHECK_CC(m->e_flags))
		p_char(m);
	else if (CHECK_PERCENT(m->e_flags))
		print_char(m, '%', 1);
}
