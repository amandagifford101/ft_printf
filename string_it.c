/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:08:35 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 18:03:35 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spaces(t_components *m)
{
	m->spaces = (m->prec >= 0 && m->prec < m->len)
	? (m->width - m->prec) : (m->width - m->len);
	write(m->fd, " ", m->spaces);
}

static void	print_string(t_components *m)
{
	m->spaces = (m->prec != -1 && m->prec < m->len)
	? (m->prec) : (m->len);
	write(m->fd, m->arg.s, m->spaces);
}
	
void	string_it(t_components *m)
{
	if (CHECK_L(m->flags))
	{
		p_widestring(m);
		return;
	}
	m->arg.s = va_arg(m->args, char*);
	ft_strcat(m->buff, m->arg.s);
	if (!m->arg.s && write(m->fd, "(NULL)", 6))
		return;
	m->len = ft_strlen(m->arg.s);
	if (CHECK_MINUS(m->flags)) // minus means left alligned
	{
		print_string(m);
		print_spaces(m);
	}
	else
	{
		print_spaces(m);
		print_string(m);
	}
}
