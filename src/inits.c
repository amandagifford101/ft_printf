/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:11:08 by agifford          #+#    #+#             */
/*   Updated: 2018/08/12 20:25:27 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_components *m, int fd, char *fmt)
{
	ft_memset(m, 0, sizeof(t_components));
	m->buff = ft_strnew(0);
	m->num = ft_strnew(0);
	m->prec = -1;
	m->fd = fd;
	m->fmt = fmt;
}

void	re_init(t_components *m)
{
	m->width = 0;
	m->prec = -1;
	m->e_flags = 0;
	m->spaces = 0;
	m->zeroes = 0;
	m->len = 0;
	m->sign = 0;
	m->num = ft_strnew(0);
}
