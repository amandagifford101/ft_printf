/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigns2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:35:37 by agifford          #+#    #+#             */
/*   Updated: 2018/08/12 20:45:03 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	field_width(t_components *m)
{
	if (ft_isdigit(m->fmt[m->i]))
		m->width = atoi(m->fmt + m->i);
	while (ft_isdigit(m->fmt[m->i]))
		m->i++;
}

int		is_prec(t_components *m)
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
		m->prec = atoi(m->fmt + m->i);
	while (ft_isdigit(m->fmt[m->i]))
		m->i++;
}

void	len_mod(t_components *m)
{
	if (m->fmt[m->i] == 'h' && m->fmt[m->i + 1] == 'h' && (m->i += 2))
		ASSIGN_HH(m->e_flags);
	else if (m->fmt[m->i] == 'h' && (m->i++))
		ASSIGN_H(m->e_flags);
	else if (m->fmt[m->i] == 'l' && m->fmt[m->i + 1] == 'l' && (m->i += 2))
		ASSIGN_LL(m->e_flags);
	else if (m->fmt[m->i] == 'l' && (m->i++))
		ASSIGN_L(m->e_flags);
	else if (m->fmt[m->i] == 'j' && (m->i++))
		ASSIGN_J(m->e_flags);
	else if (m->fmt[m->i] == 'z' && (m->i++))
		ASSIGN_Z(m->e_flags);
}
