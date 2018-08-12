/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:07:30 by agifford          #+#    #+#             */
/*   Updated: 2018/08/06 20:13:41 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_out(t_components *m)
{
	m->i++;
	if (CHECK_S(m->flags))
		string_it(m);
	else if (CHECK_SS(m->flags))
		p_wide_string(m);
	else if (CHECK_P(m->flags))
		p_pointer(m);
	else if (CHECK_D(m->flags) || CHECK_DD(m->flags) || CHECK_I(m->flags))
		p_decimal(m);
	else if (CHECK_O(m->flags) || CHECK_OO(m->flags))
		p_octal(m);
	else if (CHECK_U(m->flags) || CHECK_UU(m->flags))
		p_undecimal(m);
	else if (CHECK_X(m->flags) || CHECK_XX(m->flags))
		p_hex(m);
	else if (CHECK_C(m->flags) || CHECK_CC(m->flags))
		p_char(m);
	else if (CHECK_PERCENT(m->flags))
		m->ret = write(m->fd, "%", 1);
}

