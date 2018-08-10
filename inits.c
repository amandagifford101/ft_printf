/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:11:08 by agifford          #+#    #+#             */
/*   Updated: 2018/08/08 17:16:16 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_components *m, int fd, char *fmt)
{
	ft_memset(m, 0, sizeof(t_components));
	m->prec = -1;
	m->fd = fd;
	m->fmt = fmt;
}

/*go over init with Sean, reasons for the way different things are initialized*/
