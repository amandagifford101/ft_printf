/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_char2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 19:32:11 by agifford          #+#    #+#             */
/*   Updated: 2018/08/09 20:18:39 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(t_components *m)	
{
	m->ret += write(m->fd, m->args, 1);
}

static void	print_spaces(t_components *m)
{
	m->ret += write(m->fd, " ", m->spaces);
}

void	p_char2(t_components *m)
{
	m->arg.c = (char)va_arg(m->args, int);
	m->len = 1;
	if (CHECK_MINUS(m->flags))
	{
		print_char(m);
		print_spaces(m);
	}
	else
	{
		print_spaces(m);
		print_char(m);
	}
}

	
