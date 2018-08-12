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

/*static void	print_string(t_components *m)
{
	(void)m;
}
	m->dom = (m->prec != -1 && m->prec < m->len) ?
		(m->prec) : (m->len);
	m->ret += write(m->fd, m->arg.s, m->dom);
}*/
	
void	string_it(t_components *m)
{
	if (CHECK_L(m->flags))
	{
		p_widestring(m);
		return;
	}
	m->arg.s = va_arg(m->args, char*);
	ft_strcat(m->buff, m->arg.s);
}
 //this is pulling out a char* from va_list and plopping it in your union
/*
	if (!m->arg.s && m->ret = write(m->fd, "(NULL)", 6))
		return;
	p->str_len = ft_strlen(m->arg.s)
	if (CHECK_MINUS(m->flags)) // minus means left alligned
	{
		print_string(m);
		print_spaces_(m);
	}
	else
	{
		print_spaces(m);
		print_string(m);
	}
}
*/

