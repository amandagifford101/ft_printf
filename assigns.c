/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:04:52 by agifford          #+#    #+#             */
/*   Updated: 2018/08/06 20:20:50 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	flag_flipper(t_components *m) // I dont want to send a around unnecc.
{
	m->i++;
	assign_flags(m); //must move to next spot for all these
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
		m->fmt[m->i] == '#'|| m->fmt[m->i] == '-' || m->fmt[m->i] == '+')
	{
		if (m->fmt[m->i] == '+')
			ASSIGN_PLUS(m->flags);
		else if (m->fmt[m->i] == '-')
			ASSIGN_MINUS(m->flags);
		else if (m->fmt[m->i] == '#')
			ASSIGN_HASH(m->flags);
		else if (m->fmt[m->i] == '0')
			ASSIGN_ZERO(m->flags);
		else if (m->fmt[m->i] == ' ')
			ASSIGN_SPACE(m->flags);
		m->i++;
	}
}

void	assign_type(t_components *m)
{
	if (m->fmt[m->i] == 's')
		ASSIGN_S(m->flags);
	else if (m->fmt[m->i] == 'S')
		ASSIGN_SS(m->flags);
	else if (m->fmt[m->i] == 'p')
		ASSIGN_P(m->flags);
	else if (m->fmt[m->i] == 'd')
		ASSIGN_D(m->flags);
	else if (m->fmt[m->i] == 'D')
		ASSIGN_DD(m->flags);
	else if (m->fmt[m->i] == 'i')
		ASSIGN_I(m->flags);
	else if (m->fmt[m->i] == 'o')
		ASSIGN_O(m->flags);
	else if (m->fmt[m->i] == 'O')
		ASSIGN_OO(m->flags);
	else if (m->fmt[m->i] == 'u')
		ASSIGN_U(m->flags);
	else if (m->fmt[m->i] == 'U')
		ASSIGN_UU(m->flags);
	else if (m->fmt[m->i] == 'x')
		ASSIGN_X(m->flags);
	else if (m->fmt[m->i] == 'X')
		ASSIGN_XX(m->flags);
	else if (m->fmt[m->i] == 'c')
		ASSIGN_C(m->flags);
	else if (m->fmt[m->i] == 'C')
		ASSIGN_CC(m->flags);
	else if (m->fmt[m->i] == '%')
		ASSIGN_PERCENT(m->flags);
	m->i++;

}

void	field_width(t_components *m)
{
	if (ft_isdigit(m->fmt[m->i]))
		m->width = atoi(m->fmt + m->i);
	while (ft_isdigit(m->fmt[m->i]))
		m->i++;
}

int	is_prec(t_components *m)
{
	if (m->fmt[m->i] == '.')
	{
		m->i++;
		return (1);
	}
	return (0);
}

void	get_prec(t_components *m)
{
	if (ft_isdigit(m->fmt[m->i]))
		m->prec = atoi(m->fmt + m->i);  //add error check for else (if no digit after '.') ??
	while (ft_isdigit(m->fmt[m->i]))
		m->i++;
}

void	len_mod(t_components *m)
{
	if (m->fmt[m->i] == 'h' && m->fmt[m->i + 1] == 'h' && (m->i += 2))
		ASSIGN_HH(m->flags);
	else if (m->fmt[m->i] == 'h' && (m->i++))
		ASSIGN_H(m->flags);
	else if (m->fmt[m->i] == 'l' && m->fmt[m->i + 1] == 'l' && (m->i += 2))
		ASSIGN_LL(m->flags);
	else if (m->fmt[m->i] == 'l' && (m->i++))
		ASSIGN_L(m->flags);
	else if (m->fmt[m->i] == 'j' && (m->i++))
		ASSIGN_J(m->flags);
	else if (m->fmt[m->i] == 'z' && (m->i++))
		ASSIGN_Z(m->flags);
}
