/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:01:03 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 18:01:49 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	upper(t_components *m)
{
	int i;

	i = -1;
	while (m->num[++i])
		if (ft_isalpha(m->num[i]))
			m->num[i] -= 32;
}

static void	format(t_components *m)
{
	m->num = ft_uitoa_base(m->arg.u, 16);
	if (CHECK_XX(m->flags))
		upper(m);
	m->len = ft_strlen(m->num);
	if (m->prec > m->len)
		m->zeroes = m->prec - m->len;
	if (m->width > m->len + m->zeroes)
		m->spaces = m->width - (m->len + m->zeroes);
}

void	p_hex(t_components *m)
{
	unsign(m);
	format(m);
	if (CHECK_MINUS(m->flags))
	{
		if (CHECK_HASH(m->flags))
			(CHECK_X(m->flags)) ? (write(m->fd, "0x", 2))
			 : (write(m->fd, "0X", 2));
		print_char(m, '0', m->zeroes);
		print_num(m);
		if (m->spaces > 0)
			print_char (m, ' ', m->spaces);
	}
	else
	{
		(m->zeroes > 0) ? (print_char(m, '0', m->spaces))
			: (print_char(m, ' ', m->spaces));
		if (CHECK_HASH(m->flags))
			(CHECK_X(m->flags)) ? (write(m->fd, "0x", 2))
				: (write(m->fd, "0x", 2));
		print_char(m, '0', m->zeroes);
		print_num(m);
	}	
}

