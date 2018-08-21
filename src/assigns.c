/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:04:52 by agifford          #+#    #+#             */
/*   Updated: 2018/08/12 21:34:11 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_flipper(t_components *m)
{
	m->i++;
	assign_flags(m);
	if (ft_isdigit(m->fmt[m->i]))
		field_width(m);
	if (is_prec(m))
		get_prec(m);
	len_mod(m);
	assign_type(m);
	arg_out(m);
}

void	assign_flags(t_components *m)
{
	while (m->fmt[m->i] == '0' || m->fmt[m->i] == ' ' ||
		m->fmt[m->i] == '#' || m->fmt[m->i] == '-' || m->fmt[m->i] == '+')
	{
		if (m->fmt[m->i] == '+')
			ASSIGN_PLUS(m->e_flags);
		else if (m->fmt[m->i] == '-')
			ASSIGN_MINUS(m->e_flags);
		else if (m->fmt[m->i] == '#')
			ASSIGN_HASH(m->e_flags);
		else if (m->fmt[m->i] == '0')
			ASSIGN_ZERO(m->e_flags);
		else if (m->fmt[m->i] == ' ')
			ASSIGN_SPACE(m->e_flags);
		m->i++;
	}
}

void	assign_type(t_components *m)
{
	if (m->fmt[m->i] == 's')
		ASSIGN_S(m->e_flags);
	else if (m->fmt[m->i] == 'S')
		ASSIGN_SS(m->e_flags);
	else if (m->fmt[m->i] == 'p')
		ASSIGN_P(m->e_flags);
	else if (m->fmt[m->i] == 'd')
		ASSIGN_D(m->e_flags);
	else if (m->fmt[m->i] == 'D')
		ASSIGN_DD(m->e_flags);
	else if (m->fmt[m->i] == 'i')
		ASSIGN_I(m->e_flags);
	else if (!CHECK_S(m->e_flags) || !CHECK_SS(m->e_flags) ||
		   	!CHECK_P(m->e_flags) || !CHECK_D(m->e_flags) ||
		   	!CHECK_DD(m->e_flags) || !CHECK_I(m->e_flags))
		assign_type2(m);
	m->i++;
}

void	assign_type2(t_components *m)
{
	if (m->fmt[m->i] == 'u')
		ASSIGN_U(m->e_flags);
	else if (m->fmt[m->i] == 'U')
		ASSIGN_UU(m->e_flags);
	else if (m->fmt[m->i] == 'x')
		ASSIGN_X(m->e_flags);
	else if (m->fmt[m->i] == 'X')
		ASSIGN_XX(m->e_flags);
	else if (m->fmt[m->i] == 'c')
		ASSIGN_C(m->e_flags);
	else if (m->fmt[m->i] == 'C')
		ASSIGN_CC(m->e_flags);
	else if (m->fmt[m->i] == '%')
		ASSIGN_PERCENT(m->e_flags);
}
