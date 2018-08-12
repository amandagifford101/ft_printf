/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:59:04 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 17:59:43 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_pointer(t_components *m)
{
	m->arg.u = va_arg(m->args, unsigned long int);
	m->num = ft_uitoa_base(m->arg.u, 16);
	write(m->fd, "0x", 2);
	write(m->fd, m->num, ft_strlen(m->num));
}
